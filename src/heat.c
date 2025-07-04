/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:51:07 by gael              #+#    #+#             */
/*   Updated: 2025/07/04 16:30:08 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	generate_heat_map()
{
	// count number of alived cells and add one to ...
	int	x = 0;
	int	y = 0;

	while (y < GRID_HEIGHT_CELL)
	{
		x = 0;
		while (x < GRID_WIDTH_CELL)
		{
			if (app.maps.map[y][x] == 1)
				app.maps.heat[y][x]++;
			x++;
		}
		y++;
	}
}

void	draw_heat()
{
	int	max_x;
	int	max_y;

	max_x = app.screen_w;
	if (max_x > GRID_WIDTH_CELL * app.maps.cell_size_px)
		max_x = GRID_WIDTH_CELL * app.maps.cell_size_px;
	max_y = app.screen_h;
	if (max_y > GRID_HEIGHT_CELL * app.maps.cell_size_px)
		max_y = GRID_HEIGHT_CELL * app.maps.cell_size_px;
	for (int x = 0; x < max_x; x++)
	{
		int view_x = x + (app.maps.offset_x % app.maps.cell_size_px);
		for (int y = 0; y < max_y; y++)
		{
			int view_y = y + (app.maps.offset_y % app.maps.cell_size_px);
			// vertical lines
			if (view_y % app.maps.cell_size_px == 0)
			{
				SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
				SDL_RenderDrawLine(app.renderer,
					x + 1,
					y,
					x + app.maps.cell_size_px - 1,
					y);
			}
			// horizontal lines
			if (view_x % app.maps.cell_size_px == 0)
			{
				SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
				SDL_RenderDrawLine(app.renderer,
					x,
					y,
					x,
					y + app.maps.cell_size_px - 1);
			}
			int x_cell = (x + app.maps.offset_x) / app.maps.cell_size_px;
			int y_cell = (y + app.maps.offset_y) / app.maps.cell_size_px;
			int heat_color = 40 + (app.maps.heat[y_cell][x_cell] * 5 * 2);
			if (heat_color > 255)
				heat_color = 255;

			if (app.maps.heat[y_cell][x_cell] > 0
				&& ((x + app.maps.offset_x) % app.maps.cell_size_px) != 0
				&& ((y + app.maps.offset_y) % app.maps.cell_size_px) != 0)
			{
				SDL_SetRenderDrawColor(app.renderer, heat_color, 40, 0, 255);
				SDL_RenderDrawLine(app.renderer,
					x,
					y,
					x,
					y);
			}
		}
	}
}
