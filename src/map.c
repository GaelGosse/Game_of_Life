/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:20 by gael              #+#    #+#             */
/*   Updated: 2025/07/04 02:29:44 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	print_map(int map[GRID_HEIGHT_CELL][GRID_WIDTH_CELL])
{
	int	x;
	int	y;

	y = 0;
	while (y < GRID_HEIGHT_CELL)
	{
		x = 0;
		while (x < GRID_WIDTH_CELL)
		{
			printf("%i", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	copy_to_map()
{
	// copy map is used to apply rules and map to display
	int	x = 0;
	int	y = 0;

	while (y < GRID_HEIGHT_CELL)
	{
		x = 0;
		while (x < GRID_WIDTH_CELL)
		{
			app.maps.map[y][x] = app.maps.copy[y][x];
			x++;
		}
		y++;
	}
}

