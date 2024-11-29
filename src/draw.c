/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:18 by gael              #+#    #+#             */
/*   Updated: 2024/11/29 17:36:18 by gael             ###   ########.fr       */
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

void	draw_grid(int x_start, int y_start, int x_end, int y_end)
{
	SDL_SetRenderDrawColor(app.renderer, 128, 128, 128, 255);
	// SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);

	y_start = 0;
	x_end = SCREEN_WIDTH;
	while (y_start < SCREEN_HEIGHT)
	{
		y_end = y_start;
		SDL_RenderDrawLine(app.renderer, x_start, y_start, x_end, y_end);
		y_start += CELL_SIZE;

		if (y_start > 1000)
			break ;
	}

	y_start = 0;
	y_end = SCREEN_HEIGHT;
	while (x_start < SCREEN_WIDTH)
	{
		x_end = x_start;
		SDL_RenderDrawLine(app.renderer, x_start, y_start, x_end, y_end);
		x_start += CELL_SIZE;

		if (x_start > 1000)
			break ;
	}
}

void	draw_square(int x_start, int y_start, int len)
{
	int	limit = y_start + len;

	// horizontal lines draw
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

void render_text(const char *text, int x, int y, SDL_Color color)
{
	SDL_Surface *surface = TTF_RenderText_Solid(app.font, text, color);
	if (!surface) {
		printf("Failed to create text surface: %s\n", TTF_GetError());
		return;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(app.renderer, surface);
	if (!texture) {
		printf("Failed to create text texture: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		return;
	}

	SDL_Rect dstrect = { x, y, surface->w, surface->h };
	SDL_FreeSurface(surface);

	SDL_RenderCopy(app.renderer, texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
}
