/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:28:24 by melee             #+#    #+#             */
/*   Updated: 2023/08/18 09:28:39 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_data		data;
	t_player	player;
	t_ray		ray;
	t_img		camera;
	
	data.player = &player;
	data.ray = &ray;
	data.camera = &camera;
	
	init(&data);
	parse_map(&data);
	render_frame(&data);
	mlx_hook(data.mlx_win, KEYPRESS, 0, handle_key, &data);
	mlx_hook(data.mlx_win, DESTROY, 0, handle_destroy, &data);
	//mlx_loop_hook(data.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx_ptr);
	
	
	return (0);
}
/*
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf("%c", data.map[i][j++]);
		}
		i++;
		printf("\n");
	}
*/