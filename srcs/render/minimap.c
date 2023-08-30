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

#include "cub3d.h"

void	minimap_draw(t_data *data, t_pos i, t_pos temp, double angle)
{
	t_pos	temp_pos;
	char	*pixel;

	temp_pos.x = cos(angle) * (i.x - ((W_WIDTH / 4) / 2)) - sin(angle) \
	* (i.y - ((W_HEIGHT / 3) / 2)) + ((W_WIDTH / 4) / 2) - temp.x;
	temp_pos.y = sin(angle) * (i.x - ((W_WIDTH / 4) / 2)) + cos(angle) \
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
	int		j;
	
	i.y = -1;
	temp.x = (int)(((W_WIDTH / 4) / 2) - (data->player.posX * 10));
	temp.y = (int)(((W_HEIGHT / 3) / 2) - (data->player.posY * 10));
	double angle = atan2(data->ray.dirY, data->ray.dirX) + (M_PI / 2);
	while (++i.y < data->mini_buff.limit.y)
	{
		i.x = -1;
		while (++i.x < data->mini_buff.limit.x)
			minimap_draw(data, i, temp, angle);
	}
	j = -1;
	while (++j <= 10)
			draw_line_dda(&data->mini_buff, (t_vec){(W_WIDTH / 4) / 2 - 5 + \
		j, (W_HEIGHT / 3) / 2 - 5}, (t_pos){(W_WIDTH / 4) / 2 - 5 + j, \
		((W_HEIGHT / 3) / 2) - 5 + 10}, 0xFF0000);
}