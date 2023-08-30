/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:28:24 by melee             #+#    #+#             */
/*   Updated: 2023/08/29 11:18:34 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
