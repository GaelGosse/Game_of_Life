/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:21 by gael              #+#    #+#             */
/*   Updated: 2025/06/26 19:39:45 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	apply_rules()
{
	int	x = 0;
	int	y = 0;
	int count = 0;

	while (y < GRID_HEIGHT)
	{
		x = 0;
		while (x < GRID_WIDTH)
		{
			count = count_alive_cells(y, x);
			if (app.copy[y][x] == 1 && count != 2 && count != 3)
			{
				app.copy[y][x] = 0;
				app.stats.dead++;
				if (app.stats.alived >= 1)
					app.stats.alived--;
			}
			else if (app.copy[y][x] == 0 && count == 3)
			{
				app.copy[y][x] = 1;
				app.stats.alived++;
				app.stats.total++;
			}
			x++;
		}
		y++;
	}
	copy_to_map();
}

int	count_alive_cells(int y, int x)
{
	int	count = 0;

	if (y > 0 && x > 0 && app.map[y - 1][x - 1] == 1)
		count++;
	if (y > 0 && app.map[y - 1][x] == 1)
		count++;
	if (y > 0 && x < GRID_WIDTH -1 && app.map[y - 1][x + 1] == 1)
		count++;

	if (x > 0 && app.map[y][x - 1] == 1)
		count++;
	if (x < GRID_WIDTH -1 && app.map[y][x + 1] == 1)
		count++;

	if (y < GRID_HEIGHT -1 && x > 0 && app.map[y + 1][x - 1] == 1)
		count++;
	if (y < GRID_HEIGHT -1 && app.map[y + 1][x] == 1)
		count++;
	if (y < GRID_HEIGHT -1 && x < GRID_WIDTH -1 && app.map[y + 1][x + 1] == 1)
		count++;

	// printf("------------------------------\n");
	// printf(" %i ", app.map[y - 1][x - 1]);
	// printf(" %i ", app.map[y - 1][x]);
	// printf(" %i ", app.map[y - 1][x + 1]);
	// printf("\n");

	// printf(" %i ", app.map[y][x - 1]);
	// printf(" %i ", app.map[y][x]);
	// printf(" %i ", app.map[y][x + 1]);
	// printf("\n");

	// printf(" %i ", app.map[y + 1][x - 1]);
	// printf(" %i ", app.map[y + 1][x]);
	// printf(" %i ", app.map[y + 1][x + 1]);
	// printf("\n");

	// printf("count: %i\n", count);
	// printf("------------------------------\n");

	return (count);
}
