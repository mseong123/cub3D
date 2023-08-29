/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:56:06 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 14:56:07 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	tmpx;

	tmpx = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(-ROTSPEED) - \
	data->ray.diry * sin(-ROTSPEED);
	data->ray.diry = tmpx * sin(-ROTSPEED) + data->ray.diry * \
	cos(-ROTSPEED);
	tmpx = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-ROTSPEED) - \
	data->ray.planey * sin(-ROTSPEED);
	data->ray.planey = tmpx * sin(-ROTSPEED) + \
	data->ray.planey * cos(-ROTSPEED);
}

void	rotate_right(t_data *data)
{
	double	tmpx;

	tmpx = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(ROTSPEED) - \
	data->ray.diry * sin(ROTSPEED);
	data->ray.diry = tmpx * sin(ROTSPEED) + \
	data->ray.diry * cos(ROTSPEED);
	tmpx = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-ROTSPEED) - \
	data->ray.planey * sin(ROTSPEED);
	data->ray.planey = tmpx * sin(ROTSPEED) + \
	data->ray.planey * cos(ROTSPEED);
}
