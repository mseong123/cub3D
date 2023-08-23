/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:26:52 by melee             #+#    #+#             */
/*   Updated: 2023/08/23 08:53:00 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define W_WIDTH 1280
# define W_HEIGHT 640
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROY 17
# define MOVESPEED 0.05
# define ROTSPEED 0.025
# define T_WIDTH 640
# define T_HEIGHT 640
# define COLLISION_MOD 3
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

//libraries
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

//temp if not allowed
# include <sys/time.h>

//structs
typedef struct s_player
{
	double	posX;
	double	posY;
	bool	left;
	bool	right;
	bool	forward;
	bool	backward;
	bool	rot_left;
	bool	rot_right;
}	t_player;

typedef struct s_ray
{
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	rayX;
	double	rayY;
	double	deltaX;
	double	deltaY;
	double	sideX;
	double	sideY;
	double	perpDist;
	int		mapX;
	int		mapY;
	int		side;
	int		hit;
	int		stepX;
	int		stepY;
	int		drawStart;
	int		drawEnd;
	int		lineHeight;
}	t_ray;

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_tex
{
	int	texX;
	double step;
	double texPos;
}	t_tex;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_player		player;
	t_ray			ray;
	t_img			tex[4];
	t_tex			texture;
	char			**map;
	uint32_t		ceil_color;
	uint32_t		floor_color;
	t_img			*camera;
	int				frames;
	struct timeval	frame_start;
	char			*c_fps;
}	t_data;

//init
void	init(t_data *data);
void	init_image(t_data *data, t_img *img, int width, int height);
void	init_tex(t_data *data);
void	parse_map(t_data *data);

//handle
int		handle_keydown(int keycode, t_data *data);
int		handle_keyup(int keycode, t_data *data);
int		handle_destroy(t_data *data);

//movement
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);

//render
void	img_pix_put(t_img *img, int x, int y, uint32_t color);
void	render_frame(t_data *data);
void	set_raycast_values(t_data *data, int x);
void	calc_init_side(t_data *data);
void	dda(t_data *data);
void	cal_height(t_data *data);
void	calc_texX(t_data *data);
void	calc_texPos(t_data *data);
int		get_tex_direct(t_data *data);

#endif
