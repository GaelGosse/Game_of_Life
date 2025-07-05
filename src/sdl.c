/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:37:44 by gael              #+#    #+#             */
/*   Updated: 2025/07/04 18:02:33 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	init_SDL()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("Game of Life", \
	SDL_WINDOWPOS_UNDEFINED, \
	SDL_WINDOWPOS_UNDEFINED, \
	app.screen_w, \
	app.screen_h, \
	windowFlags);
	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", \
		app.screen_w, \
		app.screen_h, \
		SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}

void	init_SDL_font()
{
	if (TTF_Init() == -1) {
		printf("Failed to initialize SDL_ttf: %s\n", TTF_GetError());
		exit(1);
	}

	app.font = TTF_OpenFont("font/confession.ttf", 24); // Remplacez par le chemin de votre police
	if (!app.font) {
		printf("Failed to load font: %s\n", TTF_GetError());
		exit(1);
	}
}

void	prepare_scene(void)
{
	if (app.heat == PLAY)
		SDL_SetRenderDrawColor(app.renderer, 22, 22, 22, 255);
	else if (app.launched == PAUSE)
		SDL_SetRenderDrawColor(app.renderer, 22, 33, 66, 255);
	else
		SDL_SetRenderDrawColor(app.renderer, 22, 22, 22, 255);
	SDL_RenderClear(app.renderer);
}

void	present_scene(void)
{
	SDL_RenderPresent(app.renderer);
}

void	render_text(const char *text, int x, int y, SDL_Color color)
{
	// function that allow to print text at screen
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
