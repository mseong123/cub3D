/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:16:50 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 15:00:34 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	find_digit(char *str)
{
	int	i;

	i = 0;
	while (*str && ft_isdigit(*str))
	{
		i++;
		str++;
	}
	while (*str && !ft_isdigit(*str))
	{
		i++;
		str++;
	}
	return (i);
}

static unsigned int	decode_color(char *str)
{
	unsigned int	color;
	int				i;

	i = 0;
	color = 0x0;
	color += ft_atoi(str) << 16;
	i += find_digit(str);
	if (!str[i])
		return (-1);
	color += ft_atoi(str + i) << 8;
	i += find_digit(str + i);
	if (!str[i])
		return (-1);
	color += ft_atoi(str + i);
	i += find_digit(str + i);
	if (str[i] != '\0')
		return (-1);
	return (color);
}

int	assign_color(t_data *data, char *str, int space, unsigned int *bit_sign)
{
	if (!(*bit_sign & (1 << 4)) && !ft_strncmp(str, "F ", 2))
	{
		data->floor_color = decode_color(str + space);
		*bit_sign |= 1 << 4;
	}
	else if (*bit_sign & (1 << 4) && !ft_strncmp(str, "F ", 2))
		return (-1);
	if (!(*bit_sign & (1 << 5)) && !ft_strncmp(str, "C ", 2))
	{
		data->ceil_color = decode_color(str + space);
		*bit_sign |= 1 << 5;
	}
	else if (*bit_sign & (1 << 5) && !ft_strncmp(str, "C ", 2))
		return (-1);
	return (0);
}
