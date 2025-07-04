/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:15 by gael              #+#    #+#             */
/*   Updated: 2025/07/04 16:28:13 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	init_app_struct()
{
	app.renderer = NULL;
	app.window = NULL;
	app.launched = PAUSE;
	app.move = PAUSE;
	app.time = 50;
	app.screen_w = 800;
	app.screen_h = 600;
	app.play_time = 1000.0;
	app.is_clicked_dead = 0;
	app.is_clicked_alive = 0;
	memset(&app.mouse, 0, sizeof(t_mouse));
	memset(&app.stats, 0, sizeof(t_stats));
	memset(&app.maps, 0, sizeof(t_maps));
	init_SDL_font();
	init_SDL();

	app.mouse.x = 0;
	app.mouse.y = 0;
	app.mouse.x_start_move = -1;
	app.mouse.y_start_move = -1;

	memset(&app.stats.display_time, 0, 23 * sizeof(char));
	memset(&app.stats.display_move, 0, 4 * sizeof(char));
	memset(&app.stats.display_cells, 0, 20 * sizeof(char));
	memset(&app.stats.display_gen, 0, 14 * sizeof(char));
	memset(&app.stats.display_alived, 0, 17 * sizeof(char));
	memset(&app.stats.display_dead, 0, 15 * sizeof(char));
	memset(&app.stats.display_total, 0, 16 * sizeof(char));
	app.stats.visible = 0;
	app.stats.generations = 0;
	app.stats.alived = 0;
	app.stats.dead = 0;
	app.stats.total = 0;

	app.maps.initial_offset_x = 5;
	app.maps.initial_offset_y = 5;
	app.maps.offset_x = 5;
	app.maps.offset_y = 5;
	app.maps.cell_size_px = 20;
	init_map();
}

void	init_map()
{
	int	x;
	int	y;

	y = 0;
	while (y < GRID_HEIGHT_CELL)
	{
		x = 0;
		while (x < GRID_WIDTH_CELL)
		{
			app.maps.map[y][x] = 0;
			app.maps.copy[y][x] = 0;
			app.maps.heat[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	clean_up()
{
	TTF_CloseFont(app.font);
	TTF_Quit();
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}

