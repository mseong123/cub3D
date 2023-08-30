/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:28:24 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 18:10:54 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	display_fps(t_data *data)
{
	struct timeval	current_time;
	int				temp;

	data->frames++;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_sec - data->frame_start.tv_sec >= 1)
	{
		temp = data->frames / (current_time.tv_sec - data->frame_start.tv_sec);
		free(data->c_fps);
		data->c_fps = ft_itoa(temp);
		mlx_string_put(data->mlx_ptr, data->mlx_win, \
		W_WIDTH - 20, 20, 0xFFFFFF, data->c_fps);
		gettimeofday(&data->frame_start, NULL);
		data->frames = 0;
	}
	else
		mlx_string_put(data->mlx_ptr, data->mlx_win, \
		W_WIDTH - 20, 20, 0xFFFFFF, data->c_fps);
}

int	loop_handler(t_data *data)
{
	if (data->player.forward == true)
		up(data);
	if (data->player.backward == true)
		down(data);
	if (data->player.left == true)
		left(data);
	if (data->player.right == true)
		right(data);
	if (data->player.rot_left == true)
		rotate_left(data);
	if (data->player.rot_right == true)
		rotate_right(data);
	render_frame(data);
	if (data->sprite_render)
		sprite_movement(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2 || (av[1] && checkmapcub(av[1]) == -1))
		return (write(2, "Error\nInvalid/no map file included\n", 36), 1);
	init(&data, av[1]);
	mlx_hook(data.mlx_win, KEYPRESS, 0, handle_keydown, &data);
	mlx_hook(data.mlx_win, KEYRELEASE, 0, handle_keyup, &data);
	mlx_hook(data.mlx_win, DESTROY, 0, handle_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, loop_handler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
