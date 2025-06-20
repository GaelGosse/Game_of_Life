/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:07:16 by gael              #+#    #+#             */
/*   Updated: 2025/06/20 21:45:00 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H


// ------------------------------ include ----------------------------------- //
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
// color
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define UNDER_BLACK "\033[4;30m"
# define UNDER_RED "\033[4;31m"
# define UNDER_GREEN "\033[4;32m"
# define UNDER_YELLOW "\033[4;33m"
# define UNDER_BLUE "\033[4;34m"
# define UNDER_PURPLE "\033[4;35m"
# define UNDER_CYAN "\033[4;36m"
# define UNDER_WHITE "\033[4;37m"
# define BACK_BLACK "\033[0;40m"
# define BACK_RED "\033[0;41m"
# define BACK_GREEN "\033[0;42m"
# define BACK_YELLOW "\033[0;43m"
# define BACK_BLUE "\033[0;44m"
# define BACK_PURPLE "\033[0;45m"
# define BACK_CYAN "\033[0;46m"
# define BACK_WHITE "\033[0;47m"
# define RESET "\033[0m"
# define RST "\033[0m"
# define clrscr() printf("\e[1;1H\e[2J");
// ---------------------------- end include --------------------------------- //

// ------------------------------ define ------------------------------------ //
# define PLAY 1
# define PAUSE 0
# define CELL_SIZE 20
# define GRID_WIDTH 200
# define GRID_HEIGHT 200
# define SCREEN_WIDTH 40 * CELL_SIZE
# define SCREEN_HEIGHT 30 * CELL_SIZE
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_mouse
{
	int	x;
	int	y;
}		t_mouse;

typedef struct s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	t_mouse			mouse;
	int				map[GRID_HEIGHT][GRID_WIDTH];
	int				copy[GRID_HEIGHT][GRID_WIDTH];
	int				launched;
	int				time;
	int				generations;
	double			play_time;
	int				is_clicked_dead;
	int				is_clicked_alive;
	TTF_Font		*font;
}					t_app;
// ---------------------------- end struct ---------------------------------- //

//src/map.c
void	copy_to_map();
void	fill_map();
void	init_map();
void	print_map(int map[GRID_HEIGHT][GRID_WIDTH]);
//src/main.c
int		format_dimensions(int dimension);
//src/rules.c
void	apply_rules();
int		count_alive_cells(int y, int x);
//src/input.c
void	do_input(void);
//src/utils.c
char	*ft_itoa(int nbr);
int		num_len(long int nbr);
//src/init.c
void	clean_up();
void	init_SDL(int screen_h, int screen_w);
void	init_SDL_font();
void	init_app_struct(int screen_h, int screen_w);
//src/draw.c
void	draw_grid(int x_start, int y_start, int x_end, int y_end);
void	draw_square(int x_start, int y_start, int len);
void	prepare_scene(void);
void	present_scene(void);
void	render_text(const char *text, int x, int y, SDL_Color color);

#endif