/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:15 by gael              #+#    #+#             */
/*   Updated: 2025/06/26 21:26:48 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	init_SDL(int screen_h, int screen_w)
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
	screen_w, \
	screen_h, \
	windowFlags);
	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", \
		SCREEN_WIDTH, \
		SCREEN_HEIGHT, \
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

void	init_app_struct(int screen_h, int screen_w)
{
	app.renderer = NULL;
	app.window = NULL;
	init_map();
	app.view_x = 50;
	app.view_y = 50;
	app.launched = PAUSE;
	app.time = 50;
	app.play_time = 1000.0;
	app.is_clicked_dead = 0;
	app.is_clicked_alive = 0;
	memset(&app.mouse, 0, sizeof(t_mouse));
	memset(&app.stats, 0, sizeof(t_stats));
	init_SDL_font();
	init_SDL(screen_h, screen_w);

	app.mouse.x = 0;
	app.mouse.y = 0;
	memset(&app.stats.display_time, 0, 23 * sizeof(char));
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
}

void	clean_up()
{
	TTF_CloseFont(app.font);
	TTF_Quit();
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}

