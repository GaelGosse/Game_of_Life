/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:13 by gael              #+#    #+#             */
/*   Updated: 2025/07/01 01:17:56 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

t_app	app;

int	format_dimensions(int dimension)
{
	if (dimension <= 0)
	{
		printf("dimensions must be positive\n");
		exit(1);
	}
	return (dimension);
}

int	main(int argc, char **argv)
{
	int		x_start = 0,
			y_start = 0,
			x_end = 0,
			y_end = 0;
	int		screen_h = SCREEN_HEIGHT_PX;
	int		screen_w = SCREEN_WIDTH_PX;

	printf("argc: %i\n", argc);
	if (argc != 3 && argc != 1)
	{
		printf("Err: Must have no args or two (cf ./game_of_life )\n");
		return (1);
	}
	if (argc == 3)
	{
		screen_h = format_dimensions(atoi(argv[1]));
		screen_w = format_dimensions(atoi(argv[2]));
	}

	memset(&app, 0, sizeof(t_app));
	init_app_struct(screen_h, screen_w);
	atexit(clean_up);
	// clrscr();
	Uint32		last_update = SDL_GetTicks();

	printf(GREEN"grid x %i \n"RST, GRID_WIDTH_PX);
	printf(GREEN"grid y %i \n"RST, GRID_HEIGHT_PX);
	printf(GREEN"screen x %i \n"RST, SCREEN_WIDTH_PX);
	printf(GREEN"screen y %i \n"RST, SCREEN_HEIGHT_PX);
	while (1)
	{
		prepare_scene();
		draw_map();
		do_input();

		Uint32 now = SDL_GetTicks();
		if (app.launched == PLAY && (int)(now - last_update) >= app.time)
		{
			// app.stats.alived = 0;
			apply_rules();
			last_update = now;
			app.stats.generations++;
		}

		if (app.stats.visible == 1)
			display_stats();

		present_scene();

		SDL_Delay(10);
	}
	(void)x_start;
	(void)y_start;
	(void)x_end;
	(void)y_end;
	(void)argc;
	(void)argv;
}
