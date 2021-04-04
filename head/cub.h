/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:28:25 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:36:31 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <../mlx/mlx.h>
# include <math.h>

# include "get_next_line.h"

# define BYTE	unsigned char
# define RS		0.04
# define MS		0.1

/*
** ERRORS
** 1 - Malloc
** 2 - file open or read or write
** 3 - MLX
** 4 - file content
*/

typedef struct	s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sprite;
}				t_texture;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			h;
	int			w;
	int			bpp;
	int			en;
	int			line_l;
}				t_img;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_map
{
	int			r_x;
	int			r_y;
	t_texture	*text;
	t_color		*floor;
	t_color		*ceil;
}				t_map;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_plr
{
	t_vec		pos;
	t_vec		dir;
}				t_plr;

typedef struct	s_sprite
{
	double		dst;
	t_vec		pos;
}				t_sprite;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			right;
	int			left;
}				t_key;

typedef struct	s_all
{
	t_win		*win;
	t_map		*info;
	t_plr		*plr;
	t_vec		plane;
	char		**map;
	int			maph;
	double		*zbuf;
	int			snum;
	t_sprite	*sprs;
	int			on;
	t_img		**tex;
	t_key		key;
}				t_all;

typedef struct	s_draw
{
	int			side;
	int			texnum;
	double		step;
	t_point		draw;
	t_point		tex;
	t_vec		ray;

}				t_draw;

typedef struct	s_draw_sprite
{
	t_point		start;
	t_point		end;
	t_vec		transform;
}				t_draw_sprite;

/*
 ** CUB3D
*/
t_all			*print_window(char *fn);
t_all			*show_window(char *fn);
int				main_window(char *map);
int				main_picture(char *map, char *save);

/*
 ** CHECKER
*/
char			**copy_map(char **map, int h);
int				check_cub(char *fn);
int				check_map(t_all *all);
int				check_player(t_all *all);
void			checker(t_all *all);
/*
 ** CHECKER UTILS
*/
int				check_borders(int x, int y, char **map);
int				valid_point(char x);
char			*fill_empty_map(char *str, int len, const char *map);
int				check_valid_points(char **map);
int				flood_fill(int x, int y, char **map, char **paint);

/*
 ** DESTROYER
*/
void			win_destroy(t_win *win);
void			info_tex_destroy(t_texture *tex);
void			*info_destroy(t_map *map, const char *er);
void			*map_destroy(char **map, size_t h);
int				all_destroy(t_all *all);
/*
 ** DESTROYER PARTS
*/
void			img_destroy(t_all *all, t_img *img);
void			img_destroy_all(t_all *all);

/*
 ** DRAW
*/
void			my_mlx_pixel_put(t_win *win, double x, double y, size_t color);
int				draw_screen(t_all *all);

/*
 ** EXIT
*/
int				ft_exit(t_all *all);
void			exit_err(t_all *all, char *er, int ner);
void			exit_screenshot(t_all *all, int fd, char *er);
char			**ft_split_error(char **arr, int n, char *er);

/*
 ** INIT
*/
void			*init_err(t_all *all, char *er);
t_all			*init_all_null(t_all *all);
t_all			*init_all();
t_img			**init_imgs(t_all *all);
/*
 ** INIT PARTS
*/
t_map			*init_map_null(t_map *map);
t_map			*init_map(t_map *map);
t_plr			*init_plr(t_plr *plr);
t_win			*init_win(t_win *win);

/*
 ** KEY
*/
int				key_press(int key, t_all *all);
int				key_unpress(int key, t_all *all);
void			rotate(t_all *all, int side);
int				handle_key(t_all *all);
int				check_position(t_all *all, size_t x, size_t y);

/*
 ** MAP READER
*/
t_map			*get_map_info(const char *text, t_map *map);
char			**cut_map(char *text);
void			*err_read_map_info(t_all *all, char *text);
t_all			*read_map_info(int fd, t_all *all);
t_all			*parse_file(char *fn);

/*
 ** PARSER CHECK
*/
int				check_digit(const char *str, int i);
int				check_color(const char *str, int i, int *color);
int				check_comma(const char *str, int i);
int				check_spaces(int i, const char *text);
int				check_open_tex(char *path, char *tex);

t_map			*check_letter(const char *text, t_map *map);
t_map			*check_ns(const char *text, t_map *map, int i);
t_map			*check_we(const char *text, t_map *map, int i);
t_map			*check_floor_ceil(const char *text, t_map *map, int i);
int				check_resolution(int x, int y);

int				check_map_begin(const char *str);
int				check_texture(t_texture *tex);
int				check_colors(t_color *col, char *side);
int				check_map_info(t_map *map);
int				path_err(const char *text, char *path, char next);
/*
 ** PARSER GET
*/
t_map			*get_resolution(t_map *map, const char *text);
t_all			*get_sprites(t_all *all);
char			*get_path(const char *text, char next, char *path);
t_color			*get_colors(t_color *st, const char *str);
t_all			*get_map_wh(t_all *all);
/*
 ** PARSER SPLIT
*/
int				check_line_spaces(const char *str);
char			**ft_split(char *str);
int				check_before_split(char *str);
int				ft_split_lenstr(const char *str);
int				get_num_str(const char *str);

/*
 ** PLAYER READER
*/
int				check_direction(char a);
t_all			*get_direction(char a, t_all *all);
t_all			*get_plr(t_all *all);

/*
 ** SCREENSHOT
*/
int				fill_header(int fd, int size);
int				fill_info(int fd, int w, int h);
int				fill_img(int fd, int w, int h, t_all *all);
void			screenshot(t_all *all);

/*
 ** SPRITE
*/
void			prepare_sprite(t_all *all);
void			draw_point(t_all *all, t_draw_sprite dr, int stripe, int texx);
void			draw_stripe(t_all *all, t_draw_sprite dr);
void			draw_sprites(t_all *all);
/*
 ** SPRITE UTILS COUNT
*/
void			count_transform(t_all *all, t_vec *sprite, t_vec *transform,
																	size_t i);
void			count_start_sp(t_all *all, t_point *start, t_vec transform);
void			count_end_sp(t_all *all, t_point *end, t_vec transform);

/*
 ** TEXTURES
*/
void			draw_texture(t_all *all);
void			count_raydir(t_all *all, t_vec *ray, int x);
double			count_perpwall(t_all *all, t_draw *dr);
void			prepare_draw(t_all *all, t_draw *dr, int x);
void			draw_column(t_all *all, t_draw *dr, int x);
/*
 ** TEXTURES UTILS COUNT
*/
void			count_delta(t_vec ray, t_vec *delta);
int				count_start(t_all *all, int x);
int				count_end(t_all *all, int x);
double			count_wallx(t_all *all, int x, t_draw dr);
/*
 ** TEXTURES UTILS DRAW
*/
int				draw_tex(t_all *all, t_draw *dr, int x, int y);
int				choose_tex(t_draw dr);
int				hit_wall(t_all *all, t_point *map, t_point *step, t_vec ray);
int				change_side(t_vec *sidedst, t_vec delta, t_point *map,
															t_point *step);
/*
 ** TEXTURES UTILS RAY
*/
void			check_ray(t_vec ray, t_point *step, t_vec *sidedst, t_all *all);
int				rayxmin(double posx, t_vec *sidedst, int mapx, double deltax);
int				rayxmax(double posx, t_vec *sidedst, int mapx, double deltax);

/*
 ** UTILS 1
*/
void			ft_bzero(void *s, size_t n);
char			*get_img_path(t_all *all, int i);
double			ft_abs(double n);
int				get_color(t_color *c);
t_all			*bubble_sort(t_all *all);

t_vec			vec_rotate(t_vec vec, double angle);
int				ft_strcmp(const char *s1, const char *s2);
t_all			*chose_resolution(t_all *all);
int				ft_isspace(char a);
int				ft_isdigit(char a);

int				get_num(int i, const char *text, int *n);
int				get_n(const char *str);
int				get_len(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strcat_text(char *dst, char *src);

#endif
