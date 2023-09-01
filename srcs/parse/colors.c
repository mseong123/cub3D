/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:16:50 by lewlee            #+#    #+#             */
/*   Updated: 2023/09/01 13:01:33 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	decode_color(char *str)
{
	int				bit_shift;
	int				temp;
	unsigned int	color;

	bit_shift = 16;
	color = 0x0;
	while (*str)
	{
		temp = ft_atoi(str);
		if (temp < 0 || temp > 255)
			return (-1);
		color += temp << bit_shift;
		bit_shift -= 8;
		while (ft_isdigit(*str))
			str++;
		if (*str == '\0')
			break ;
		str++;
		if (!ft_isdigit(*str))
			return (-1);
	}
	if (bit_shift != -8)
		return (-1);
	return (color);
}

int	assign_color(t_data *data, char *str, int space, unsigned int *bit_sign)
{
	if (!(*bit_sign & (1 << 4)) && !ft_strncmp(str, "F ", 2))
	{
		data->floor_color = decode_color(str + space);
		*bit_sign |= 1 << 4;
		return (0);
	}
	else if (*bit_sign & (1 << 4) && !ft_strncmp(str, "F ", 2))
		return (-1);
	if (!(*bit_sign & (1 << 5)) && !ft_strncmp(str, "C ", 2))
	{
		data->ceil_color = decode_color(str + space);
		*bit_sign |= 1 << 5;
		return (0);
	}
	else if (*bit_sign & (1 << 5) && !ft_strncmp(str, "C ", 2))
		return (-1);
	if (str[0] != '\n')
		return (-1);
	return (0);
}
