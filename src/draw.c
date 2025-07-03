/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:18 by gael              #+#    #+#             */
/*   Updated: 2025/07/03 23:07:11 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	draw_map()
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
			if (app.maps.map[y_cell][x_cell] == 1
				&& ((x + app.maps.offset_x) % app.maps.cell_size_px) != 0
				&& ((y + app.maps.offset_y) % app.maps.cell_size_px) != 0)
			{
				if (app.launched == PAUSE)
					SDL_SetRenderDrawColor(app.renderer, 128, 146, 255, 255);
				else
					SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
				SDL_RenderDrawLine(app.renderer,
					x,
					y,
					x,
					y);
			}
		}
	}
}

void	draw_square(int x_start, int y_start, int len)
{
	int	limit = y_start + len;

	// draw with horizontal lines
	y_start++;
	while (y_start < limit)
	{
		SDL_RenderDrawLine(app.renderer,
			x_start + 1,
			y_start,
			x_start + len - 1,
			y_start);
		y_start++;
	}
}

