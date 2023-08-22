/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:28:24 by melee             #+#    #+#             */
/*   Updated: 2023/08/22 10:33:32 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_camera(t_data *data, int x)
{
	int y;

	y = data->ray->drawStart;
	while (y < data->ray->drawEnd)
	{
		if (data->ray->side == 1)
			img_pix_put(data->camera, x, y, 0xFF00);
		else
			img_pix_put(data->camera, x, y, 0xFF00/2);
		y++;
	}
}

int	loop_handler(t_data *data)
{
	init_image(data, data->camera, W_WIDTH, W_HEIGHT);

	if (data->player->forward == true)
		up(data);
	if (data->player->backward == true)
		down(data);
	if (data->player->left == true)
		left(data);
	if (data->player->right == true)
		right(data);
	if (data->player->rot_left == true)
		rotate_left(data);
	if (data->player->rot_right == true)
		rotate_right(data);
		
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	
	int	x = 0;
	while(x < W_WIDTH)
	{
		set_raycast_values(data, x);
		calc_init_side(data);
		dda(data);
		cal_height(data);
		fill_camera(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->camera->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->camera->mlx_img);
	return (0);
}

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
	// render_frame(&data);
	mlx_hook(data.mlx_win, KEYPRESS, 0, handle_keydown, &data);
	mlx_hook(data.mlx_win, KEYRELEASE, 0, handle_keyup, &data);
	mlx_hook(data.mlx_win, DESTROY, 0, handle_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, loop_handler, &data);
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