/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:09 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 19:01:12 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_sprite_img3(t_data *data)
{
	int	height;
	int	width;

	data->sprite.sprite_img[12].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic6.xpm", &width, &height);
	data->sprite.sprite_img[12].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[12].mlx_img, &data->sprite.sprite_img[12].bpp, \
	&data->sprite.sprite_img[12].line_len, &data->sprite.sprite_img[12].endian);
	data->sprite.sprite_img[13].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sonic9.xpm", \
	&width, &height);
	data->sprite.sprite_img[13].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[13].mlx_img, &data->sprite.sprite_img[13].bpp, \
	&data->sprite.sprite_img[13].line_len, &data->sprite.sprite_img[13].endian);
	data->sprite.sprite_img[14].mlx_img = \
	mlx_xpm_file_to_image(data->mlx_ptr, "./assets/sonic10.xpm", \
	&width, &height);
	data->sprite.sprite_img[14].addr = \
	mlx_get_data_addr(data->sprite.sprite_img[14].mlx_img, \
	&data->sprite.sprite_img[14].bpp, &data->sprite.sprite_img[14].line_len, \
	&data->sprite.sprite_img[14].endian);
}

void	init_sprite_img2(t_data *data)
{
	int	height;
	int	width;

	data->sprite.sprite_img[8].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic7.xpm", &width, &height);
	data->sprite.sprite_img[8].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[8].mlx_img, &data->sprite.sprite_img[8].bpp, \
	&data->sprite.sprite_img[8].line_len, &data->sprite.sprite_img[8].endian);
	data->sprite.sprite_img[9].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic8.xpm", &width, &height);
	data->sprite.sprite_img[9].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[9].mlx_img, &data->sprite.sprite_img[9].bpp, \
	&data->sprite.sprite_img[9].line_len, &data->sprite.sprite_img[9].endian);
	data->sprite.sprite_img[10].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic7.xpm", &width, &height);
	data->sprite.sprite_img[10].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[10].mlx_img, &data->sprite.sprite_img[10].bpp, \
	&data->sprite.sprite_img[10].line_len, &data->sprite.sprite_img[10].endian);
	data->sprite.sprite_img[11].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic8.xpm", &width, &height);
	data->sprite.sprite_img[11].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[11].mlx_img, &data->sprite.sprite_img[11].bpp, \
	&data->sprite.sprite_img[11].line_len, &data->sprite.sprite_img[11].endian);
	init_sprite_img3(data);
}

void	init_sprite_img1(t_data *data)
{
	int	height;
	int	width;

	data->sprite.sprite_img[4].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic5.xpm", &width, &height);
	data->sprite.sprite_img[4].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[4].mlx_img, &data->sprite.sprite_img[4].bpp, \
	&data->sprite.sprite_img[4].line_len, &data->sprite.sprite_img[4].endian);
	data->sprite.sprite_img[5].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic6.xpm", &width, &height);
	data->sprite.sprite_img[5].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[5].mlx_img, &data->sprite.sprite_img[5].bpp, \
	&data->sprite.sprite_img[5].line_len, &data->sprite.sprite_img[5].endian);
	data->sprite.sprite_img[6].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic7.xpm", &width, &height);
	data->sprite.sprite_img[6].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[6].mlx_img, &data->sprite.sprite_img[6].bpp, \
	&data->sprite.sprite_img[6].line_len, &data->sprite.sprite_img[6].endian);
	data->sprite.sprite_img[7].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic8.xpm", &width, &height);
	data->sprite.sprite_img[7].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[7].mlx_img, &data->sprite.sprite_img[7].bpp, \
	&data->sprite.sprite_img[7].line_len, &data->sprite.sprite_img[7].endian);
	init_sprite_img2(data);
}

void	init_sprite_img(t_data *data)
{
	int	height;
	int	width;

	data->sprite.sprite_img[0].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic1.xpm", &width, &height);
	data->sprite.sprite_img[0].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[0].mlx_img, &data->sprite.sprite_img[0].bpp, \
	&data->sprite.sprite_img[0].line_len, &data->sprite.sprite_img[0].endian);
	data->sprite.sprite_img[1].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic2.xpm", &width, &height);
	data->sprite.sprite_img[1].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[1].mlx_img, &data->sprite.sprite_img[1].bpp, \
	&data->sprite.sprite_img[1].line_len, &data->sprite.sprite_img[1].endian);
	data->sprite.sprite_img[2].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic3.xpm", &width, &height);
	data->sprite.sprite_img[2].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[2].mlx_img, &data->sprite.sprite_img[2].bpp, \
	&data->sprite.sprite_img[2].line_len, &data->sprite.sprite_img[2].endian);
	data->sprite.sprite_img[3].mlx_img = mlx_xpm_file_to_image \
	(data->mlx_ptr, "./assets/sonic4.xpm", &width, &height);
	data->sprite.sprite_img[3].addr = mlx_get_data_addr \
	(data->sprite.sprite_img[3].mlx_img, &data->sprite.sprite_img[3].bpp, \
	&data->sprite.sprite_img[3].line_len, &data->sprite.sprite_img[3].endian);
	init_sprite_img1(data);
}
