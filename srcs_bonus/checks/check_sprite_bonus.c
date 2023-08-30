/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:18:14 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 18:44:44 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_sprite(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{
				init_sprite(&data->sprite);
				init_sprite_img(data);
				data->sprite.posx = j + 0.5;
				data->sprite.posy = i + 0.5;
				data->sprite_render = 1;
				break ;
			}
			j++;
		}
		i++;
	}
}
