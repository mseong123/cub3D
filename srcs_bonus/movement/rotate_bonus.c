/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:56:06 by melee             #+#    #+#             */
/*   Updated: 2023/09/01 10:43:37 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_data *data, int mouse)
{
	double	tmpx;
	double	rotspeed;

	if (mouse)
		rotspeed = ROTSPEEDMOUSE;
	else
		rotspeed = ROTSPEED;
	tmpx = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(-rotspeed) - \
	data->ray.diry * sin(-rotspeed);
	data->ray.diry = tmpx * sin(-rotspeed) + data->ray.diry * \
	cos(-rotspeed);
	tmpx = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-rotspeed) - \
	data->ray.planey * sin(-rotspeed);
	data->ray.planey = tmpx * sin(-rotspeed) + \
	data->ray.planey * cos(-rotspeed);
}

void	rotate_right(t_data *data, int mouse)
{
	double	tmpx;
	double	rotspeed;

	if (mouse)
		rotspeed = ROTSPEEDMOUSE;
	else
		rotspeed = ROTSPEED;
	tmpx = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(rotspeed) - \
	data->ray.diry * sin(rotspeed);
	data->ray.diry = tmpx * sin(rotspeed) + \
	data->ray.diry * cos(rotspeed);
	tmpx = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-rotspeed) - \
	data->ray.planey * sin(rotspeed);
	data->ray.planey = tmpx * sin(rotspeed) + \
	data->ray.planey * cos(rotspeed);
}
