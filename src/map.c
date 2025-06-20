/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:20 by gael              #+#    #+#             */
/*   Updated: 2025/06/21 00:16:28 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	init_map()
{
	int	x;
	int	y;

	y = 0;
	while (y < GRID_HEIGHT)
	{
		x = 0;
		while (x < GRID_WIDTH)
		{
			app.map[y][x] = 0;
			app.copy[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	print_map(int map[GRID_HEIGHT][GRID_WIDTH])
{
	int	x;
	int	y;

	y = 0;
	while (y < GRID_HEIGHT)
	{
		x = 0;
		while (x < GRID_WIDTH)
		{
			printf(" %i ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	copy_to_map()
{
	int	x = 0;
	int	y = 0;

	while (y < GRID_HEIGHT)
	{
		x = 0;
		while (x < GRID_WIDTH)
		{
			app.map[y][x] = app.copy[y][x];
			x++;
		}
		y++;
	}
}
