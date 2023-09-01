/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:55:57 by melee             #+#    #+#             */
/*   Updated: 2023/09/01 10:46:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	handle_mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x == W_WIDTH / 2)
		return (0);
	else if (x < W_WIDTH / 2)
		rotate_left(data, 1);
	else if (x > W_WIDTH / 2)
		rotate_right(data, 1);
	mlx_mouse_move(data->mlx_win, W_WIDTH / 2, W_HEIGHT / 2);
	return (0);
}
