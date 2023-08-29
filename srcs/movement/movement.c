/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:56:02 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 14:56:03 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up(t_data *data)
{
	if (ft_strchr(" 0NSEW", data->map[(int)data->player.posy] \
	[(int)(data->player.posx + data->ray.dirx * MOVESPEED * COLLISION_MOD)]))
		data->player.posx += data->ray.dirx * MOVESPEED;
	if (ft_strchr(" 0NSEW", data->map[(int)(data->player.posy + \
	data->ray.diry * MOVESPEED * COLLISION_MOD)][(int)data->player.posx]))
		data->player.posy += data->ray.diry * MOVESPEED;
}

void	down(t_data *data)
{
	if (ft_strchr(" 0NSEW", data->map[(int)data->player.posy] \
	[(int)(data->player.posx - data->ray.dirx * MOVESPEED * COLLISION_MOD)]))
		data->player.posx -= data->ray.dirx * MOVESPEED;
	if (ft_strchr(" 0NSEW", data->map[(int)(data->player.posy - \
	data->ray.diry * MOVESPEED * COLLISION_MOD)][(int)data->player.posx]))
		data->player.posy -= data->ray.diry * MOVESPEED;
}

void	left(t_data *data)
{
	if (ft_strchr(" 0NSEW", data->map[(int)data->player.posy] \
	[(int)(data->player.posx + data->ray.diry * MOVESPEED * COLLISION_MOD)]))
		data->player.posx += data->ray.diry * MOVESPEED;
	if (ft_strchr(" 0NSEW", data->map[(int)(data->player.posy - \
	data->ray.dirx * MOVESPEED * COLLISION_MOD)][(int)data->player.posx]))
		data->player.posy -= data->ray.dirx * MOVESPEED;
}

void	right(t_data *data)
{
	if (ft_strchr(" 0NSEW", data->map[(int)data->player.posy] \
	[(int)(data->player.posx - data->ray.diry * MOVESPEED * COLLISION_MOD)]))
		data->player.posx -= data->ray.diry * MOVESPEED;
	if (ft_strchr(" 0NSEW", data->map[(int)(data->player.posy + \
	data->ray.dirx * MOVESPEED * COLLISION_MOD)][(int)data->player.posx]))
		data->player.posy += data->ray.dirx * MOVESPEED;
}
