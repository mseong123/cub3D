/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:16:44 by lewlee            #+#    #+#             */
/*   Updated: 2023/09/01 12:44:17 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	find_space(char *s)
{
	int	i;

	i = 1;
	while (s[++i])
		if (s[i] != ' ')
			return (i);
	return (0);
}

static int	get_image(t_data *data, char *str, int i, unsigned int *bit_sign)
{
	int		fd;
	int		width;
	int		height;

	fd = open(str, O_RDWR);
	if (fd < 0)
		return (-1);
	close(fd);
	data->tex[i].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, str, \
	&width, &height);
	data->tex[i].addr = mlx_get_data_addr(data->tex[i].mlx_img, \
	&data->tex[i].bpp, &data->tex[i].line_len, &data->tex[i].endian);
	*bit_sign |= 1 << i;
	return (0);
}

static int	assign_img(t_data *data, char *str, unsigned int *bit_sign)
{
	int	space;

	space = find_space(str);
	if (!(*bit_sign & 1) && !ft_strncmp(str, "NO ", 3))
		return (get_image(data, str + space, NORTH, bit_sign));
	else if (*bit_sign & 1 && !ft_strncmp(str, "NO ", 3))
		return (-1);
	if (!(*bit_sign & (1 << 1)) && !ft_strncmp(str, "SO ", 3))
		return (get_image(data, str + space, SOUTH, bit_sign));
	else if (*bit_sign & (1 << 1) && !ft_strncmp(str, "SO ", 3))
		return (-1);
	if (!(*bit_sign & (1 << 2)) && !ft_strncmp(str, "EA ", 3))
		return (get_image(data, str + space, EAST, bit_sign));
	else if (*bit_sign & (1 << 2) && !ft_strncmp(str, "EA ", 3))
		return (-1);
	if (!(*bit_sign & (1 << 3)) && !ft_strncmp(str, "WE ", 3))
		return (get_image(data, str + space, WEST, bit_sign));
	else if (*bit_sign & (1 << 3) && !ft_strncmp(str, "WE ", 3))
		return (-1);
	if (assign_color(data, str, space, bit_sign) == -1)
		return (-1);
	return (0);
}

int	getfileinfo(t_data *data, char **file)
{
	int				i;
	int				n;
	unsigned int	bit_sign;

	i = -1;
	bit_sign = 0;
	n = array2d_y(file);
	while (--n >= 0)
		if (ft_isalpha(file[n][0]))
			break ;
	n++;
	while (++i < n)
		if (assign_img(data, file[i], &bit_sign) == -1)
			break ;
	if (bit_sign == 63 && data->ceil_color >= 0 && data->ceil_color <= 16777215
		&& data->floor_color >= 0 && data->floor_color <= 16777215)
		return (i);
	return (-1);
}
