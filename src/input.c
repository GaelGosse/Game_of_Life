/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:01 by gael              #+#    #+#             */
/*   Updated: 2025/06/21 01:23:31 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	mouse_click_down(t_app *app, int x_mouse, int y_mouse)
{
	if (app->launched == PAUSE)
	{
		x_mouse = app->mouse.x / CELL_SIZE + app->view_x;
		y_mouse = app->mouse.y / CELL_SIZE + app->view_y;
		if (app->map[y_mouse][x_mouse] == 0)
		{
			app->is_clicked_alive = 0;
			app->is_clicked_dead = 1;
			app->map[y_mouse][x_mouse] = 1;
			app->copy[y_mouse][x_mouse] = 1;
		}
		else
		{
			app->is_clicked_alive = 1;
			app->is_clicked_dead = 0;
			app->map[y_mouse][x_mouse] = 0;
			app->copy[y_mouse][x_mouse] = 0;
		}
	}
}

void	mouse_click_move(t_app *app, int x_mouse, int y_mouse)
{
	if (app->launched == PAUSE)
	{
		x_mouse = app->mouse.x / CELL_SIZE + app->view_x;
		y_mouse = app->mouse.y / CELL_SIZE + app->view_y;
		if (app->is_clicked_alive == 1)
		{
			app->map[y_mouse][x_mouse] = 0;
			app->copy[y_mouse][x_mouse] = 0;
		}
		else if (app->is_clicked_dead == 1)
		{
			app->map[y_mouse][x_mouse] = 1;
			app->copy[y_mouse][x_mouse] = 1;
		}
	}
}

void	arrow_up(t_app *app)
{
	if (app->play_time < 5000)
		app->play_time *= 1.1;
	if (app->launched == PLAY)
		app->time = (int)app->play_time;
	else
		app->time = 50;
}

void	arrow_down(t_app *app)
{
	if (app->play_time > 50)
		app->play_time *= 0.9;
	if (app->launched == PLAY)
		app->time = (int)app->play_time;
	else
		app->time = 50;
}

void	space_bar(t_app *app)
{
	if (app->launched == PLAY)
	{
		app->launched = PAUSE;
		app->time = 50;
	}
	else
	{
		app->launched = PLAY;
		app->time = (int)app->play_time;
	}
}

void	do_input(void)
{
	SDL_Event	event;
	int			x_mouse = 0;
	int			y_mouse = 0;

	SDL_GetMouseState(&app.mouse.x, &app.mouse.y);
	while (SDL_PollEvent(&event))
	{
		// printf("app.play_time: %f\n", app.play_time);
		// printf("event.type: %i\n", event.type);
		// printf("event.key.keysym.scancode: %i\n", event.key.keysym.scancode);
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
					case 21:
						// r : reset
						if (app.launched == PAUSE)
							init_map();
						break;
					case 41:
						// esc
						exit(0);
						break;
					case 44:
						space_bar(&app);
						break;
					case 82:
						arrow_up(&app);
						break;
					case 81:
						arrow_down(&app);
						break;
					default:
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouse_click_down(&app, x_mouse, y_mouse);
				break;
			case SDL_MOUSEBUTTONUP:
				app.is_clicked_alive = 0;
				app.is_clicked_dead = 0;
				break;
			case SDL_MOUSEMOTION:
				mouse_click_move(&app, x_mouse, y_mouse);
				break;
			default:
				break;
		} // switch event.type
	} // while SDL poll event
}
