/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:07:16 by gael              #+#    #+#             */
/*   Updated: 2025/07/02 17:04:33 by gael             ###   ########.fr       */
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
# define CELL_SIZE_PX 20
# define GRID_WIDTH_CELL 50
# define GRID_HEIGHT_CELL 50
# define GRID_WIDTH_PX GRID_WIDTH_CELL * CELL_SIZE_PX
# define GRID_HEIGHT_PX GRID_HEIGHT_CELL * CELL_SIZE_PX
# define SCREEN_WIDTH_PX 800
# define SCREEN_HEIGHT_PX 600
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_mouse
{
	int	x;
	int	y;
	int	x_start_move;
	int	y_start_move;
}		t_mouse;

typedef struct s_stats
{
	int		visible; // 0 or 1
	char	display_time[23];
	char	display_move[4];
	char	display_cells[20];
	char	display_gen[14];
	char	display_alived[17];
	char	display_dead[15];
	char	display_total[16];
	int		generations;
	int		alived;
	int		dead;
	int		total;
}		t_stats;

typedef struct s_maps
{
	int				map[GRID_HEIGHT_CELL][GRID_WIDTH_CELL];
	int				copy[GRID_HEIGHT_CELL][GRID_WIDTH_CELL];
	int				heat[GRID_HEIGHT_CELL][GRID_WIDTH_CELL];
	int				initial_offset_x; // px
	int				initial_offset_y; // px
	int				offset_x; // px
	int				offset_y; // px
}	t_maps;

typedef struct s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	int				launched; // PLAY / PAUSE
	int				move; // PLAY / PAUSE
	int				time; // ms
	double			play_time; // ms
	int				is_clicked_dead; // 0 or 1
	int				is_clicked_alive; // 0 or 1
	t_mouse			mouse;
	t_stats			stats;
	t_maps			maps;
	TTF_Font		*font;
}					t_app;
// ---------------------------- end struct ---------------------------------- //

//src/map.c
void	copy_to_map();
void	init_map();
void	print_map(int map[GRID_HEIGHT_CELL][GRID_WIDTH_CELL]);
//src/main.c
int		format_dimensions(int dimension);
//src/display.c
void	display_stats();
//src/rules.c
void	apply_rules();
int		count_alive_cells(int y, int x);
//src/input.c
void	arrow_down(t_app *app);
void	arrow_up(t_app *app);
void	do_input(void);
void	mouse_click_down(t_app *app, int x_mouse, int y_mouse);
void	mouse_click_move(t_app *app, int x_mouse, int y_mouse);
void	space_bar(t_app *app);
//src/utils.c
char	*ft_itoa(int nbr);
int		num_len(long int nbr);
//src/init.c
void	clean_up();
void	init_SDL(int screen_h, int screen_w);
void	init_SDL_font();
void	init_app_struct(int screen_h, int screen_w);
//src/draw.c
void	draw_map();
void	draw_square(int x_start, int y_start, int len);
void	prepare_scene(void);
void	present_scene(void);
void	render_text(const char *text, int x, int y, SDL_Color color);
//src/stats.c
void	count_cells(void);

#endif