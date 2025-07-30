/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:21 by gael              #+#    #+#             */
/*   Updated: 2025/07/30 23:08:55 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	apply_rules()
{
	// Apply Game of Life rules :
	// Dead cell become alive if 3 cells around
	// Alive cell become dead if there are not 2 or 3 cells alive around
	int	x = 0;
	int	y = 0;
	int count = 0;

	while (y < GRID_HEIGHT_CELL)
	{
		x = 0;
		while (x < GRID_WIDTH_CELL)
		{
			count = count_alive_cells_around(y, x);
			if (app.maps.copy[y][x] == 1 && count != 2 && count != 3)
			{
				app.maps.copy[y][x] = 0;
				app.stats.dead++;
				if (app.stats.alived >= 1)
				{
					app.stats.alived--;
					// app.maps.heat[y][x]--;
				}
			}
			else if (app.maps.copy[y][x] == 0 && count == 3)
			{
				app.maps.copy[y][x] = 1;
				app.maps.heat[y][x]++;
				app.stats.alived++;
				app.stats.total++;
			}
			x++;
		}
		y++;
	}
	copy_to_map();
}

int	count_alive_cells_around(int y, int x)
{
	int	count = 0;

	if (y > 0 && x > 0 && app.maps.map[y - 1][x - 1] == 1)
		count++;
	if (y > 0 && app.maps.map[y - 1][x] == 1)
		count++;
	if (y > 0 && x < GRID_WIDTH_CELL -1 && app.maps.map[y - 1][x + 1] == 1)
		count++;

	if (x > 0 && app.maps.map[y][x - 1] == 1)
		count++;
	if (x < GRID_WIDTH_CELL -1 && app.maps.map[y][x + 1] == 1)
		count++;

	if (y < GRID_HEIGHT_CELL -1 && x > 0 && app.maps.map[y + 1][x - 1] == 1)
		count++;
	if (y < GRID_HEIGHT_CELL -1 && app.maps.map[y + 1][x] == 1)
		count++;
	if (y < GRID_HEIGHT_CELL -1 && x < GRID_WIDTH_CELL -1 && app.maps.map[y + 1][x + 1] == 1)
		count++;

	// printf("------------------------------\n");
	// printf(" %i ", app.maps.map[y - 1][x - 1]);
	// printf(" %i ", app.maps.map[y - 1][x]);
	// printf(" %i ", app.maps.map[y - 1][x + 1]);
	// printf("\n");

	// printf(" %i ", app.maps.map[y][x - 1]);
	// printf(" %i ", app.maps.map[y][x]);
	// printf(" %i ", app.maps.map[y][x + 1]);
	// printf("\n");

	// printf(" %i ", app.maps.map[y + 1][x - 1]);
	// printf(" %i ", app.maps.map[y + 1][x]);
	// printf(" %i ", app.maps.map[y + 1][x + 1]);
	// printf("\n");

	// printf("count: %i\n", count);
	// printf("------------------------------\n");

	return (count);
}

