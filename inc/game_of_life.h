/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc/game_of_life.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:07:16 by gael              #+#    #+#             */
/*   Updated: 2025/07/04 16:28:21 by gael             ###   ########.fr       */
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
# define GRID_WIDTH_CELL 50
# define GRID_HEIGHT_CELL 50
# define GRID_WIDTH_PX GRID_WIDTH_CELL * 20
# define GRID_HEIGHT_PX GRID_HEIGHT_CELL * 20
# define SCREEN_WIDTH_PX 800
# define SCREEN_HEIGHT_PX 600
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_mouse
{
	int	x;
	int	y;
	int	x_start_move; // used to help move mouse
	int	y_start_move; // used to help move mouse
}		t_mouse;

typedef struct s_stats
{
	int		visible; // (0 or 1) : if stats is visible or not at screen
	char	display_coor_x[7];
	char	display_coor_y[7];
	char	display_zoom[8];
	char	display_time[23];
	char	display_move[4];
	char	display_cells[20];
	char	display_gen[14];
	char	display_alived[17];
	char	display_dead[15];
	char	display_total[16];
	int		generations; // nbr of frame since PLAY
	int		alived; // actual alive cell in PLAY time
	int		dead; // count number of deaths
	int		total; // all time number of lived cells
}		t_stats;

typedef struct s_maps
{
	int				grid_width_cell; // (cell) : size of map by cells
	int				grid_height_cell; // (cell) : size of map by cells
	int				map[GRID_HEIGHT_CELL][GRID_WIDTH_CELL]; // map is used to display
	int				copy[GRID_HEIGHT_CELL][GRID_WIDTH_CELL]; // copy map is used to apply rules
	int				heat[GRID_HEIGHT_CELL][GRID_WIDTH_CELL]; // map with most living cells
	int				initial_offset_x; // (px) : used to help moving with mouse
	int				initial_offset_y; // (px) : used to help moving with mouse
	int				offset_x; // (px) : offset used to display map
	int				offset_y; // (px) : offset used to display map
	int				cell_size_px; // (px) : size of a single cell
}	t_maps;

typedef struct s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	int				launched; // (PLAY / PAUSE) : used to apply rules or let user draw cells
	int				move; // (PLAY / PAUSE) : allow user to move or draw
	int				heat; // (PLAY / PAUSE) : display heat map
	int				time; // (ms) : time since this program has been executed
	double			play_time; // (ms) : time between frame
	int				is_clicked_dead; // (0 or 1) :
	int				is_clicked_alive; // (0 or 1) :
	int				screen_w;
	int				screen_h;
	t_mouse			mouse;
	t_stats			stats;
	t_maps			maps;
	TTF_Font		*font;
}					t_app;
// ---------------------------- end struct ---------------------------------- //

//src/map.c
void	copy_to_map();
void	print_map(int map[GRID_HEIGHT_CELL][GRID_WIDTH_CELL]);
//src/heat.c
void	draw_heat();
void	generate_heat_map();
//src/main.c
int		format_dimensions(int dimension);
//src/display.c
void	display_stats();
//src/rules.c
void	apply_rules();
int		count_alive_cells_around(int y, int x);
//src/input.c
void	arrow_down(t_app *app);
void	arrow_up(t_app *app);
void	do_input(void);
void	mouse_click_down(t_app *app, int x_mouse, int y_mouse);
void	mouse_click_move(t_app *app, int x_mouse, int y_mouse);
void	space_bar(t_app *app);
void	zoom_in(t_app *app);
void	zoom_out(t_app *app);
//src/utils.c
int		abs(int nbr);
char	*ft_itoa(int nbr);
int		num_len(long int nbr);
//src/init.c
void	clean_up();
void	init_app_struct();
void	init_map();
//src/draw.c
void	draw_map();
void	draw_square(int x_start, int y_start, int len);
//src/sdl.c
void	init_SDL();
void	init_SDL_font();
void	prepare_scene(void);
void	present_scene(void);
void	render_text(const char *text, int x, int y, SDL_Color color);

#endif