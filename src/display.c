/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:44:24 by gael              #+#    #+#             */
/*   Updated: 2025/06/30 18:50:20 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

void	display_stats()
{
	SDL_Color	white = {255, 255, 255, 255};

	strcpy(app.stats.display_time, "Time per frame (ms): ");
	strcat(app.stats.display_time, ft_itoa(app.play_time));
	render_text(app.stats.display_time, 10, 10, white);

	if (app.move == PLAY)
		strcpy(app.stats.display_move, "Move");
	else
		strcpy(app.stats.display_move, "Click");
	render_text(app.stats.display_move, 300, 10, white);

	strcpy(app.stats.display_cells, "Cells");
	render_text(app.stats.display_cells, 10, 540, white);

	strcpy(app.stats.display_gen, "Gen: ");
	strcat(app.stats.display_gen, ft_itoa(app.stats.generations));
	render_text(app.stats.display_gen, 10, 570, white);

	strcpy(app.stats.display_alived, "Alived: ");
	strcat(app.stats.display_alived, ft_itoa(app.stats.alived));
	render_text(app.stats.display_alived, 160, 570, white);

	strcpy(app.stats.display_dead, "Dead: ");
	strcat(app.stats.display_dead, ft_itoa(app.stats.dead));
	render_text(app.stats.display_dead, 310, 570, white);

	strcpy(app.stats.display_total, "Total: ");
	strcat(app.stats.display_total, ft_itoa(app.stats.total));
	render_text(app.stats.display_total, 460, 570, white);
}
