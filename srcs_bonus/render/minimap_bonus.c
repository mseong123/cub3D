/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:08:05 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/30 11:16:34 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_minirays(t_data *data, t_vec start, t_pos new_xy, int color)
{
	int		steps;
	float	x;
	float	y;
	char	*pixel;

	if (fabs(new_xy.x - start.x) > fabs(new_xy.y - start.y))
		steps = fabs(new_xy.x - start.x) + 1;
	else
		steps = fabs(new_xy.y - start.y) + 1;
	x = (new_xy.x - start.x) / steps;
	y = (new_xy.y - start.y) / steps;
	while (--steps >= 0)
	{
		pixel = data->mini_buff.addr + ((int)start.y * data->mini_buff.line_len \
		+ (int)start.x * (data->mini_buff.bpp / 8));
		start.x += x;
		start.y += y;
		if (*(int *)pixel == 0x555555 || *(int *)pixel == 0x55000000)
			break ;
		else if (*(int *)pixel == color)
			continue ;
		if (start.x - x >= 0 && start.x - x < data->mini_buff.limit.x
			&& start.y - y >= 0 && start.y - y < data->mini_buff.limit.y)
			img_pix_put(&data->mini_buff, start.x - x, start.y - y, color);
	}
}

void	minimap_draw(t_data *data, t_pos i, t_pos temp, t_vec angle)
{
	t_pos	temp_pos;
	char	*pixel;

	temp_pos.x = angle.x * (i.x - ((W_WIDTH / 4) / 2)) - angle.y \
	* (i.y - ((W_HEIGHT / 3) / 2)) + ((W_WIDTH / 4) / 2) - temp.x;
	temp_pos.y = angle.y * (i.x - ((W_WIDTH / 4) / 2)) + angle.x \
	* (i.y - ((W_HEIGHT / 3) / 2)) + ((W_HEIGHT / 3) / 2) - temp.y;
	if (temp_pos.x >= 0 && temp_pos.x < data->minimap.limit.x
		&& temp_pos.y >= 0 && temp_pos.y < data->minimap.limit.y)
	{
		pixel = (&data->minimap)->addr + (temp_pos.y * \
		(&data->minimap)->line_len + temp_pos.x * ((&data->minimap)->bpp / 8));
		img_pix_put(&data->mini_buff, i.x, i.y, *(int *)pixel);
	}
	else
		img_pix_put(&data->mini_buff, i.x, i.y, 0x55000000);
}

void	minimap(t_data *data)
{
	t_pos	i;
	t_pos	temp;
	t_vec	angle;

	i.y = -1;
	temp.x = (int)(((W_WIDTH / 4) / 2) - (data->player.posx * 10));
	temp.y = (int)(((W_HEIGHT / 3) / 2) - (data->player.posy * 10));
	angle.x = atan2(data->ray.diry, data->ray.dirx) + (M_PI / 2);
	angle.y = sin(angle.x);
	angle.x = cos(angle.x);
	while (++i.y < data->mini_buff.limit.y)
	{
		i.x = -1;
		while (++i.x < data->mini_buff.limit.x)
			minimap_draw(data, i, temp, angle);
	}
	i.y = -1;
	while (++i.y < 170)
		draw_minirays(data, (t_vec){(W_WIDTH / 4) / 2, (W_HEIGHT / 3) / 2}, \
	(t_pos){((W_WIDTH / 4) / 2 - 85) + i.y, 0}, 0xDDDDDD);
	i.y = 8;
	while (--i.y > 0)
		draw_line_dda(&data->mini_buff, (t_vec){(W_WIDTH / 4) / 2 + \
	(i.y - 1), (W_HEIGHT / 3) / 2 - 5 + i.y}, (t_pos){(W_WIDTH / 4) / 2 - \
	(i.y - 1), (W_HEIGHT / 3) / 2 - 5 + i.y}, 0xFF0000);
}
