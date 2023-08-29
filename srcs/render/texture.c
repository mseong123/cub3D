/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:55:46 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 14:55:47 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_wallx(t_data *data)
{
	double	wallx;

	if (data->ray.side == 0)
		wallx = data->player.posy + data->ray.perpdist * data->ray.rayy;
	else
		wallx = data->player.posx + data->ray.perpdist * data->ray.rayx;
	wallx -= floor((wallx));
	return (wallx);
}

void	calc_texx(t_data *data)
{
	double	wallx;
	int		texx;

	if (data->ray.side == 0)
		wallx = data->player.posy + data->ray.perpdist * data->ray.rayy;
	else
		wallx = data->player.posx + data->ray.perpdist * data->ray.rayx;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)T_WIDTH);
	if (data->ray.side == 0 && data->ray.rayx > 0)
		texx = T_WIDTH - texx - 1;
	if (data->ray.side == 1 && data->ray.rayy < 0)
		texx = T_WIDTH - texx - 1;
	data->texture.texx = texx;
}

void	calc_texpos(t_data *data)
{
	data->texture.step = 1.0 * T_HEIGHT / data->ray.lineheight;
	data->texture.texpos = (data->ray.drawstart - W_HEIGHT / 2 + \
	data->ray.lineheight / 2) * data->texture.step;
}

int	get_tex_direct(t_data *data)
{
	if (data->ray.side == 0 && data->ray.rayx < 0)
		return (WEST);
	else if (data->ray.side == 0 && data->ray.rayx > 0)
		return (EAST);
	else if (data->ray.side == 1 && data->ray.rayy > 0)
		return (SOUTH);
	else
		return (NORTH);
}
