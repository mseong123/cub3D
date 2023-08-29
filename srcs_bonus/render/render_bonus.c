/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:58:11 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/29 14:55:39 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	img_pix_put(t_img *img, int x, int y, uint32_t color)
{
	char	*pixel;

	pixel = img->addr;
	pixel += (img->line_len * y) + (x * (img->bpp / 8));
	*(uint32_t *)pixel = color;
}

void	fill_ceil_floor(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i < data->ray.drawstart)
		img_pix_put(&data->camera, x, i++, data->ceil_color);
	i = data->ray.drawend;
	while (i < W_HEIGHT)
		img_pix_put(&data->camera, x, i++, data->floor_color);
}

void	draw_camera(t_data *data, int x)
{
	int			texy;
	int			drawstart;
	uint32_t	*tex_addr;
	uint32_t	color;
	int			tex_direct;

	calc_texx(data);
	calc_texpos(data);
	drawstart = data->ray.drawstart;
	fill_ceil_floor(data, x);
	tex_direct = get_tex_direct(data);
	while (drawstart < data->ray.drawend)
	{
		texy = (int)data->texture.texpos & (T_HEIGHT - 1);
		data->texture.texpos += data->texture.step;
		tex_addr = (uint32_t *)(data->tex[tex_direct].addr + \
		((texy * data->tex[tex_direct].line_len) + \
		(data->texture.texx * (data->tex[tex_direct].bpp / 8))));
		color = *tex_addr;
		if (tex_direct == NORTH || tex_direct == SOUTH)
			color = (color >> 1) & 8355711;
		img_pix_put(&data->camera, x, drawstart, color);
		drawstart++;
	}
}

void	render_frame(t_data *data)
{
	int	x;

	x = 0;
	init_image(data, &data->camera, W_WIDTH, W_HEIGHT);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	while (x < W_WIDTH)
	{
		set_raycast_values(data, x);
		calc_init_side(data);
		dda(data);
		cal_height(data);
		draw_camera(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->camera.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->camera.mlx_img);
}
