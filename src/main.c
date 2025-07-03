/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:13 by gael              #+#    #+#             */
/*   Updated: 2025/07/03 03:48:34 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

t_app	app;

int	format_dimensions(int dimension)
{
	if (dimension <= 0)
	{
		printf("dimensions must be positive and \n");
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

	printf("argc: %i\n", argc);
	if (argc != 3 && argc != 1)
	{
		printf("Err: Must have no args or two (cf ./game_of_life )\n");
		return (1);
	}
	if (argc == 3)
	{
		app.maps.grid_height_cell = format_dimensions(atoi(argv[1]));
		app.maps.grid_width_cell = format_dimensions(atoi(argv[2]));
	}

	memset(&app, 0, sizeof(t_app));
	init_app_struct();
	atexit(clean_up);

	Uint32		last_update = SDL_GetTicks();
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
