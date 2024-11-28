/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:01 by gael              #+#    #+#             */
/*   Updated: 2024/11/28 16:18:57 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void do_input(void)
{
	SDL_Event	event;
	int			x_mouse = 0;
	int			y_mouse = 0;

	SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
	while (SDL_PollEvent(&event))
	{
		// printf(RED"special key: %i\n"RESET, event.type);
		// printf("alphabet: %i\n", event.key.keysym.scancode);
		// printf("\n");
		printf("app.play_time: %f\n", app.play_time);
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;
			case 1026:
				// mouse click up
				app.is_clicked_alive = 0;
				app.is_clicked_dead = 0;
				break;
			case 1025:
				// mouse click down

				if (app.launched == PAUSE)
				{
					x_mouse = app.mouse.x / CELL_SIZE;
					y_mouse = app.mouse.y / CELL_SIZE;
					if (app.map[y_mouse][x_mouse] == 0)
					{
						app.is_clicked_alive = 0;
						app.is_clicked_dead = 1;
					}
					else
					{
						app.is_clicked_alive = 1;
						app.is_clicked_dead = 0;
					}
					// printf("app.is_clicked_dead: %i\n", app.is_clicked_dead);
					// printf("app.is_clicked_alive: %i\n", app.is_clicked_alive);
					// printf("\n");
					x_mouse = app.mouse.x / CELL_SIZE;
					y_mouse = app.mouse.y / CELL_SIZE;
					if (app.map[y_mouse][x_mouse] == 0)
					{
						app.map[y_mouse][x_mouse] = 1;
						app.copy[y_mouse][x_mouse] = 1;
					}
					else
					{
						app.map[y_mouse][x_mouse] = 0;
						app.copy[y_mouse][x_mouse] = 0;
					}
					// print_map(app.copy);
					// count_alive_cells(y_mouse, x_mouse);
				}
				break;
			case 1024:
				// mouse move
				if (app.launched == PAUSE)
				{
					x_mouse = app.mouse.x / CELL_SIZE;
					y_mouse = app.mouse.y / CELL_SIZE;
					if (app.is_clicked_alive == 1)
					{
						app.map[y_mouse][x_mouse] = 0;
						app.copy[y_mouse][x_mouse] = 0;
					}
					else if (app.is_clicked_dead == 1)
					{
						app.map[y_mouse][x_mouse] = 1;
						app.copy[y_mouse][x_mouse] = 1;
					}
				}
				break;
			default:
				clrscr();
				break;
		}
		switch (event.key.keysym.scancode)
		{
			case 41:
				// esc
				exit(0);
				break;
			case 44:
				// space
				if (app.launched == PLAY)
				{
					app.launched = PAUSE;
					app.time = 50;
				}
				else
				{
					app.launched = PLAY;
					app.time = (int)app.play_time;
				}
				break;
			case 82:
				if (event.type == 768 && app.play_time < 5000)
					app.play_time *= 1.1;
				if (app.launched == PLAY)
					app.time = (int)app.play_time;
				else
					app.time = 50;
				break;
			case 81:
				if (event.type == 768 && app.play_time > 50)
					app.play_time *= 0.9;
				if (app.launched == PLAY)
					app.time = (int)app.play_time;
				else
					app.time = 50;
				break;
			default:
				clrscr();
				break;
		}
		// printf("\n");
	}
}
