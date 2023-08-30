/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:33:59 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 18:43:12 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_dir(t_pos *dir)
{
	dir[0].x = 1;
	dir[0].y = 0;
	dir[1].x = 0;
	dir[1].y = 1;
	dir[2].x = -1;
	dir[2].y = 0;
	dir[3].x = 0;
	dir[3].y = -1;
}

double	get_sprite_speed(t_data *data)
{
	if (data->sprite.i == 5 || data->sprite.i == 12)
		return (0.3);
	else if (data->sprite.i >= 6 && data->sprite.i <= 11)
		return (0.5);
	else
		return (0.1);
}

void	move(t_pos *dir, t_data *data, double speed)
{
	data->sprite.posx += speed * dir[data->sprite.dir_index].x;
	data->sprite.posy += speed * dir[data->sprite.dir_index].y;
}

void	sprite_movement(t_data *data)
{
	double	speed;
	t_pos	dir[4];

	init_dir(dir);
	data->sprite.tick++;
	if (data->sprite.tick == TICK)
	{
		speed = get_sprite_speed(data);
		if (data->map[(int)(data->sprite.posy + dir[data->sprite. \
		dir_index].y * speed * COL_S)][(int)(data->sprite.posx + dir \
		[data->sprite.dir_index].x * speed * COL_S)] != '1')
			move(dir, data, speed);
		else
		{
			data->sprite.dir_index ++;
			if (data->sprite.dir_index == 4)
				data->sprite.dir_index = 0;
		}
		data->sprite.i++;
		if (data->sprite.i == 15)
			data->sprite.i = 0;
		data->sprite.tick = 0;
	}	
}
