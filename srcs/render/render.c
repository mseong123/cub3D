/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:58:11 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/23 08:55:12 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, uint32_t color)
{
	char	*pixel;

	pixel = img->addr + (img->line_len * y) + (x * (img->bpp/8));
	*(uint32_t *)pixel = color;
}

void	fill_ceil_floor(t_data *data, int x)
{
	int i;

	i = 0;
	while (i < data->ray.drawStart)
		img_pix_put(data->camera, x, i++, data->ceil_color);
	i = data->ray.drawEnd;
	while (i < W_HEIGHT)
		img_pix_put(data->camera, x, i++, data->floor_color);
}

void	draw_camera(t_data *data, int x)
{
	int texY;
	int drawStart;
	uint32_t *tex_addr;
	uint32_t color;
	int	tex_direct;

	calc_texX(data);
	calc_texPos(data);
	drawStart = data->ray.drawStart;
	fill_ceil_floor(data, x);
	tex_direct = get_tex_direct(data);
	while (drawStart < data->ray.drawEnd)
	{
		texY = (int)data->texture.texPos & (T_HEIGHT - 1);
		data->texture.texPos += data->texture.step;
		tex_addr = (uint32_t *)(data->tex[tex_direct].addr + ((texY * data->tex[tex_direct].line_len) + (data->texture.texX * (data->tex[tex_direct].bpp/8))));
		color = *tex_addr;
		if (tex_direct == NORTH || tex_direct == SOUTH)
			color = (color >> 1) & 8355711;
		img_pix_put(data->camera, x, drawStart, color);
		drawStart++;
	}
}

void	render_frame(t_data *data)
{
	int	x;

	x = 0;
	init_image(data, data->camera, W_WIDTH, W_HEIGHT);
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
	data->camera->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->camera->mlx_img);
}





