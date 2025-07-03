/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:01 by gael              #+#    #+#             */
/*   Updated: 2025/07/03 23:20:55 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	mouse_click_down(t_app *app, int x_mouse, int y_mouse)
{
	if (app->launched == PAUSE && app->move == PAUSE)
	{
		x_mouse = (app->mouse.x + app->maps.offset_x) / app->maps.cell_size_px;
		y_mouse = (app->mouse.y + app->maps.offset_y) / app->maps.cell_size_px;
		if (app->maps.map[y_mouse][x_mouse] == 0)
		{
			app->is_clicked_alive = 0;
			app->is_clicked_dead = 1;
			app->maps.map[y_mouse][x_mouse] = 1;
			app->maps.copy[y_mouse][x_mouse] = 1;
			app->stats.alived++;
			app->stats.total++;
		}
		else
		{
			app->is_clicked_alive = 1;
			app->is_clicked_dead = 0;
			app->maps.map[y_mouse][x_mouse] = 0;
			app->maps.copy[y_mouse][x_mouse] = 0;
			app->stats.alived--;
			app->stats.total--;
		}
	}
	else if (app->move == PLAY)
	{
		app->mouse.x_start_move = app->mouse.x;
		app->mouse.y_start_move = app->mouse.y;
	}
}

void	mouse_click_move(t_app *app, int x_mouse, int y_mouse)
{
	if (app->launched == PAUSE && app->move == PAUSE)
	{
		x_mouse = (app->mouse.x + app->maps.offset_x) / app->maps.cell_size_px;
		y_mouse = (app->mouse.y + app->maps.offset_y) / app->maps.cell_size_px;
		if (app->is_clicked_alive == 1 && app->maps.map[y_mouse][x_mouse] == 1)
		{
			app->maps.map[y_mouse][x_mouse] = 0;
			app->maps.copy[y_mouse][x_mouse] = 0;
			app->stats.alived--;
			app->stats.total--;
		}
		else if (app->is_clicked_dead == 1 && app->maps.map[y_mouse][x_mouse] == 0)
		{
			app->stats.alived++;
			app->stats.total++;
			app->maps.map[y_mouse][x_mouse] = 1;
			app->maps.copy[y_mouse][x_mouse] = 1;
		}
	}
	else if (app->move == PLAY && app->mouse.x_start_move != -1)
	{
		int move_x = (int)((app->mouse.x_start_move - app->mouse.x) / 5);
		if (app->maps.initial_offset_x + move_x < 0)
			move_x = -app->maps.initial_offset_x;
		if (app->maps.initial_offset_x + move_x >= GRID_WIDTH_PX - app->screen_w)
			move_x = (GRID_WIDTH_PX - app->screen_w) - app->maps.initial_offset_x;

		int move_y = (int)((app->mouse.y_start_move - app->mouse.y) / 5);
		if (app->maps.initial_offset_y + move_y < 0)
			move_y = -app->maps.initial_offset_y;
		if (app->maps.initial_offset_y + move_y >= GRID_HEIGHT_PX - app->screen_h)
			move_y = (GRID_HEIGHT_PX - app->screen_h) - app->maps.initial_offset_y;

		// printf(PURPLE"%i %i (%i %i)"RESET"\n", move_x, move_y, app->maps.offset_x, app->maps.offset_y);
		app->maps.offset_x = app->maps.initial_offset_x + move_x;
		app->maps.offset_y = app->maps.initial_offset_y + move_y;
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

void	zoom_in(t_app *app)
{
	if (app->maps.cell_size_px < 30)
		app->maps.cell_size_px++;
}

void	zoom_out(t_app *app)
{
	if (app->maps.cell_size_px > 10)
		app->maps.cell_size_px--;
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
					case 11:
						// h: stats
						if (app.stats.visible == 0)
							app.stats.visible = 1;
						else
							app.stats.visible = 0;
						break;
					case 21:
						// r : reset
						if (app.launched == PAUSE)
						{
							app.stats.generations = 0;
							app.stats.alived = 0;
							app.stats.dead = 0;
							app.stats.total = 0;
							init_map();
						}
						break;
					case 25:
						// v : move
						if (app.move == PAUSE)
							app.move = PLAY;
						else
							app.move = PAUSE;
						break;
					case 41:
						// esc
						exit(0);
						break;
					case 44:
						space_bar(&app);
						break;
					case 75:
						zoom_in(&app);
						break;
					case 78:
						zoom_out(&app);
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
				app.mouse.x_start_move = -1;
				app.mouse.y_start_move = -1;
				app.maps.initial_offset_x = app.maps.offset_x;
				app.maps.initial_offset_y = app.maps.offset_y;
				break;
			case SDL_MOUSEMOTION:
				mouse_click_move(&app, x_mouse, y_mouse);
				break;
			default:
				break;
		} // switch event.type
	} // while SDL poll event
}
