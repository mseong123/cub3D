/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:55:35 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 14:55:36 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_raycast_values(t_data *data, int x)
{
	double	camerax;

	camerax = 2 * x / (double)W_WIDTH - 1;
	data->ray.rayx = data->ray.dirx + (data->ray.planex * camerax);
	data->ray.rayy = data->ray.diry + (data->ray.planey * camerax);
	data->ray.mapx = (int)data->player.posx;
	data->ray.mapy = (int)data->player.posy;
	data->ray.deltax = fabs(1 / data->ray.rayx);
	data->ray.deltay = fabs(1 / data->ray.rayy);
}

void	calc_init_side(t_data *data)
{
	if (data->ray.rayx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidex = (data->player.posx - data->ray.mapx) * \
		data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidex = (data->ray.mapx + 1.0 - data->player.posx) * \
		data->ray.deltax;
	}
	if (data->ray.rayy < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidey = (data->player.posy - data->ray.mapy) * \
		data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidey = (data->ray.mapy + 1.0 - data->player.posy) * \
		data->ray.deltay;
	}
}

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.sidex < data->ray.sidey)
		{
			data->ray.sidex += data->ray.deltax;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidey += data->ray.deltay;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpdist = data->ray.sidex - data->ray.deltax;
	else
		data->ray.perpdist = data->ray.sidey - data->ray.deltay;
}

void	cal_height(t_data *data)
{
	int	lineheight;

	lineheight = (int)(W_HEIGHT / data->ray.perpdist);
	data->ray.lineheight = lineheight;
	data->ray.drawstart = -lineheight / 2 + W_HEIGHT / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = lineheight / 2 + W_HEIGHT / 2;
	if (data->ray.drawend >= W_HEIGHT)
		data->ray.drawend = W_HEIGHT - 1;
}
