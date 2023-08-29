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

double calc_wallX(t_data *data)
{
	double wallX;

	if (data->ray.side == 0)
		wallX = data->player.posY + data->ray.perpDist * data->ray.rayY;
	else           
		wallX = data->player.posX + data->ray.perpDist * data->ray.rayX;
	wallX -= floor((wallX));
	return (wallX);
}

void	calc_texX(t_data *data)
{
	double wallX;
	int texX;

	if (data->ray.side == 0)
		wallX = data->player.posY + data->ray.perpDist * data->ray.rayY;
	else           
		wallX = data->player.posX + data->ray.perpDist * data->ray.rayX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)T_WIDTH);
	if(data->ray.side == 0 && data->ray.rayX > 0)
		texX = T_WIDTH - texX - 1;
	if(data->ray.side == 1 && data->ray.rayY < 0)
		texX = T_WIDTH - texX - 1;
	data->texture.texX = texX;
}

void	calc_texPos(t_data *data)
{
	data->texture.step = 1.0 * T_HEIGHT / data->ray.lineHeight;
	data->texture.texPos = (data->ray.drawStart - W_HEIGHT / 2 + data->ray.lineHeight / 2) * data->texture.step;
}

int	get_tex_direct(t_data *data)
{
	if (data->ray.side == 0 && data->ray.rayX < 0)
		return (WEST);
	else if (data->ray.side == 0 && data->ray.rayX > 0)
		return (EAST);
	else if (data->ray.side == 1 && data->ray.rayY > 0)
		return (SOUTH);
	else
		return (NORTH);
}

