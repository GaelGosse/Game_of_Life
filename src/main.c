/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:13 by gael              #+#    #+#             */
/*   Updated: 2024/11/30 00:10:14 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

t_app	app;

int	main(int argc, char **argv)
{
	int		x_start = 0,
			y_start = 0,
			x_end = 0,
			y_end = 0;
	char	display_time[23];
	char	*seconds_in_str;

	memset(&app, 0, sizeof(t_app));
	init_app_struct();
	atexit(clean_up);
	// clrscr();
	SDL_Color white = { 255, 255, 255, 255 };

	while (1)
	{
		prepare_scene();

		draw_grid(x_start, y_start, x_end, y_end);

		do_input();
		fill_map();
		if (app.launched == PLAY)
			apply_rules();

		seconds_in_str = ft_itoa(app.play_time);
		strcpy(display_time, "Time per frame (ms): ");
		strcat(display_time, seconds_in_str);

		render_text(display_time, 10, 10, white);
		present_scene();

		SDL_Delay(app.time);
	}
	(void)x_start;
	(void)y_start;
	(void)x_end;
	(void)y_end;
	(void)argc;
	(void)argv;
}
