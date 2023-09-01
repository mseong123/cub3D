/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:26:52 by melee             #+#    #+#             */
/*   Updated: 2023/09/01 10:49:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define W_WIDTH 1280
# define W_HEIGHT 720
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROY 17
# define MOVESPEED 0.05
# define ROTSPEED 0.025
# define T_WIDTH 512
# define T_HEIGHT 512
# define COLLISION_MOD 3
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
//bonus macros
# define S_WIDTH 100
# define S_HEIGHT 125
# define UDIV 1.8
# define VDIV 1.6
# define VMOVE 180
# define TICK 5
# define COL_S 2
# define MOUSEMOVE 6
# define ROTSPEEDMOUSE 0.04

//libraries
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>

//structs
typedef struct s_player
{
	double	posx;
	double	posy;
	bool	left;
	bool	right;
	bool	forward;
	bool	backward;
	bool	rot_left;
	bool	rot_right;
}	t_player;

typedef struct s_ray
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	rayx;
	double	rayy;
	double	deltax;
	double	deltay;
	double	sidex;
	double	sidey;
	double	perpdist;
	int		mapx;
	int		mapy;
	int		side;
	int		hit;
	int		stepx;
	int		stepy;
	int		drawstart;
	int		drawend;
	int		lineheight;
}	t_ray;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_pos	limit;
}	t_img;

typedef struct s_tex
{
	int		texx;
	double	step;
	double	texpos;
}	t_tex;

typedef struct s_map
{
	char	**map;
	int		**visited;
	t_pos	max;
	t_pos	start;
	int		*flag;
}	t_map;

typedef struct s_sprite
{
	double	posx;
	double	posy;
	int		reverse;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	double	zbuffer[W_WIDTH];
	int		vmovescreen;
	int		i;
	int		tick;
	double	stepy;
	double	texpos;
	int		texx;
	int		texy;
	int		dir_index;
	t_img	sprite_img[15];
}	t_sprite;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_player		player;
	t_ray			ray;
	t_img			tex[4];
	t_tex			texture;
	t_img			camera;
	t_sprite		sprite;
	int				sprite_render;
	char			**map;
	uint32_t		ceil_color;
	uint32_t		floor_color;
	t_img			minimap;
	t_img			mini_buff;
	int				frames;
	struct timeval	frame_start;
	char			*c_fps;
}	t_data;

//init
void	init(t_data *data, char *str);
void	init_image(t_data *data, t_img *img, int width, int height);
void	init_tex(t_data *data);
char	**get_file(char *filename);
int		getfileinfo(t_data *data, char **file);
void	get_map(t_data *data, char **file, int i);
void	dfs_init(t_map *map_dfs, t_data *data);
int		**init_visited(char **map);
void	init_minimap(t_data *data);
void	init_sprite(t_sprite *sprite);

//handle
int		handle_keydown(int keycode, t_data *data);
int		handle_keyup(int keycode, t_data *data);
int		handle_destroy(t_data *data);
int		handle_mouse(int x, int y, t_data *data);

//movement
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	rotate_left(t_data *data, int mouse);
void	rotate_right(t_data *data, int mouse);
void	sprite_movement(t_data *data);

//render
void	img_pix_put(t_img *img, int x, int y, uint32_t color);
void	render_frame(t_data *data);
void	set_raycast_values(t_data *data, int x);
void	calc_init_side(t_data *data);
void	dda(t_data *data, int x);
void	cal_height(t_data *data);
void	calc_texx(t_data *data);
void	calc_texpos(t_data *data);
int		get_tex_direct(t_data *data);
void	minimap(t_data *data);
void	display_fps(t_data *data);
void	draw_sprite(t_data *data);

//checks
int		checkmapcub(char *s);
int		checkmapchar(char **map, t_data *data);
int		dfs(t_map *map, t_pos move);
void	check_sprite(t_data *data);

//parsing
int		assign_color(t_data *data, char *str, int space, unsigned int *bits);
void	init_sprite_img(t_data *data);

//utils
int		array2d_y(char **c);
void	free2d_int(int **a, int n);
void	free2d_char(char **a, int n);
t_pos	find_player(char **map);
void	draw_line_dda(t_img *info, t_vec start, t_pos new_xy, int color);

#endif