/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:18 by gael              #+#    #+#             */
/*   Updated: 2025/06/28 22:09:44 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	prepare_scene(void)
{
	if (app.launched == PAUSE)
		SDL_SetRenderDrawColor(app.renderer, 22, 33, 66, 255);
	else
		SDL_SetRenderDrawColor(app.renderer, 22, 22, 22, 255);
	SDL_RenderClear(app.renderer);
}

void	present_scene(void)
{
	SDL_RenderPresent(app.renderer);
}

void	draw_map()
{
	for (int x = 0; x < SCREEN_WIDTH_PX; x++)
	{
		int view_x = x + (app.maps.offset_x % CELL_SIZE_PX);
		for (int y = 0; y < SCREEN_HEIGHT_PX; y++)
		{
			int view_y = y + (app.maps.offset_y % CELL_SIZE_PX);
			if (view_y % CELL_SIZE_PX == 0)
			{
				SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
				SDL_RenderDrawLine(app.renderer,
					x + 1,
					y,
					x + CELL_SIZE_PX - 1,
					y);
			}
			if (view_x % CELL_SIZE_PX == 0)
			{
				SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
				SDL_RenderDrawLine(app.renderer,
					x,
					y,
					x,
					y + CELL_SIZE_PX - 1);
			}
			int y_cell = (y + app.maps.offset_x) / CELL_SIZE_PX;
			int x_cell = (x + app.maps.offset_y) / CELL_SIZE_PX;
			if (app.maps.map[y_cell][x_cell] == 1
				&& ((x + app.maps.offset_x) % CELL_SIZE_PX) != 0
				&& ((y + app.maps.offset_y) % CELL_SIZE_PX) != 0)
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

void	render_text(const char *text, int x, int y, SDL_Color color)
{
	SDL_Surface *surface = TTF_RenderText_Solid(app.font, text, color);
	if (!surface)
	{
		printf("Failed to create text surface: %s\n", TTF_GetError());
		return;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(app.renderer, surface);
	if (!texture)
	{
		printf("Failed to create text texture: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		return;
	}

	SDL_Rect dstrect = { x, y, surface->w, surface->h };
	SDL_FreeSurface(surface);

	SDL_RenderCopy(app.renderer, texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
}
