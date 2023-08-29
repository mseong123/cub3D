/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:55:57 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 14:55:58 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keydown(int keycode, t_data *data)
{
	if (keycode == 13)
		data->player.forward = true;
	else if (keycode == 0)
		data->player.left = true;
	else if (keycode == 2)
		data->player.right = true;
	else if (keycode == 1)
		data->player.backward = true;
	else if (keycode == 123)
		data->player.rot_left = true;
	else if (keycode == 124)
		data->player.rot_right = true;
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keyup(int keycode, t_data *data)
{
	if (keycode == 13)
		data->player.forward = false;
	else if (keycode == 0)
		data->player.left = false;
	else if (keycode == 2)
		data->player.right = false;
	else if (keycode == 1)
		data->player.backward = false;
	else if (keycode == 123)
		data->player.rot_left = false;
	else if (keycode == 124)
		data->player.rot_right = false;
	return (0);
}

int	handle_destroy(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}
