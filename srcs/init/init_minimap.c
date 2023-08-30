/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:02:54 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/30 11:20:39 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_block(t_img *img, t_pos start, int type)
{
	int	i;

	i = -1;
	
	if (type == 0)
		while (++i <= 10)
			draw_line_dda(img, (t_vec){start.x + i, start.y}, (t_pos){start.x + i, start.y + 10}, 0xDDDDDD);
	else if (type == 1)
		while (++i <= 10)
			draw_line_dda(img, (t_vec){start.x + i, start.y}, (t_pos){start.x + i, start.y + 10}, 0x555555);
	else
		while (++i <= 10)
			draw_line_dda(img, (t_vec){start.x + i, start.y}, (t_pos){start.x + i, start.y + 10}, 0x55000000);
}

void	init_minimap(t_data *data)
{
	int j;
	int i;

	i = -1;
	(&data->minimap)->limit = (t_pos){ft_strlen(data->map[0]) * 10, array2d_y(data->map) * 10};
	(&data->minimap)->mlx_img = mlx_new_image(data->mlx_ptr, data->minimap.limit.x, data->minimap.limit.y);
	(&data->minimap)->addr = mlx_get_data_addr(data->minimap.mlx_img, &data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				draw_block(&data->minimap, (t_pos){j * 10, i * 10}, 1);
			else if (ft_strchr("0NSEW", data->map[i][j]))
				draw_block(&data->minimap, (t_pos){j * 10, i * 10}, 0);
			else
				draw_block(&data->minimap, (t_pos){j * 10, i * 10}, 2);
		}
	}
}