/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:18 by gael              #+#    #+#             */
/*   Updated: 2025/06/26 00:15:24 by gael             ###   ########.fr       */
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
	for (int y = 0; y < SCREEN_HEIGHT / CELL_SIZE; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH / CELL_SIZE; x++)
		{
			int map_y = app.view_y + y;
			int map_x = app.view_x + x;

			SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
			SDL_RenderDrawLine(app.renderer,
				x * CELL_SIZE,
				y * CELL_SIZE,
				x * CELL_SIZE + CELL_SIZE,
				y * CELL_SIZE
			);
			SDL_RenderDrawLine(app.renderer,
				x * CELL_SIZE,
				y * CELL_SIZE,
				x * CELL_SIZE,
				y * CELL_SIZE + CELL_SIZE
			);

			if (x >= 0 && x < GRID_WIDTH*CELL_SIZE
				&& y >= 0 && y < GRID_HEIGHT*CELL_SIZE
				&& map_x >= 0 && map_x < GRID_WIDTH
				&& map_y >= 0 && map_y < GRID_HEIGHT
				&& app.map[map_y][map_x] == 1)
			{
				if (app.launched == PAUSE)
					SDL_SetRenderDrawColor(app.renderer, 128, 146, 255, 255);
				else
					SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
				draw_square(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE);
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
