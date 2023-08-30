/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:38:07 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/29 14:55:00 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->dirx = 0;
	ray->diry = 0;
	ray->planex = 0;
	ray->planey = 0;
	ray->rayx = 0;
	ray->rayy = 0;
	ray->deltax = 0;
	ray->deltay = 0;
	ray->sidex = 0;
	ray->sidey = 0;
	ray->perpdist = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->side = 0;
	ray->hit = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->lineheight = 0;
}

void	init_player(t_player *player)
{
	player->forward = false;
	player->backward = false;
	player->left = false;
	player->right = false;
	player->rot_left = false;
	player->rot_right = false;
}

void	init_image(t_data *data, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(data->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, \
	&img->line_len, &img->endian);
}

void	init1(t_data *data, char **file)
{
	t_map	dfs_info;

	get_map(data, file, getfileinfo(data, file));
	dfs_init(&dfs_info, data);
	init_player(&data->player);
	init_ray(&data->ray);
	(&data->texture)->texx = 0;
	(&data->texture)->step = 0;
	(&data->texture)->texpos = 0;
	if (checkmapchar(data->map, data) == -1)
		exit (write(2, "Error\nInvalid characte", 23) \
		- write(2, "rs/player not found \n", 22));
	if (dfs(&dfs_info, dfs_info.start) != 1 && *dfs_info.flag == 1)
		exit (write(2, "Error\nInvalid", 14) - write(2, " map layout\n", 13));
	free(dfs_info.flag);
	free2d_int(dfs_info.visited, dfs_info.max.y + 2);
	free2d_char(dfs_info.map, dfs_info.max.y);
	data->player.posy = find_player(data->map).y + 0.5;
	data->player.posx = find_player(data->map).x + 0.5;
}

void	init(t_data *data, char *str)
{
	char	**file;

	file = get_file(str);
	if (!file || !*file)
	{
		perror("cub3D");
		exit (1);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("cub3D");
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, \
	W_WIDTH, W_HEIGHT, "cub3D");
	if (!data->mlx_win)
	{
		perror("cub3D");
		exit(EXIT_FAILURE);
	}
	init1(data, file);
}
