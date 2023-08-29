/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:16:26 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 13:48:41 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	array2d_y(char **c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

void	free2d_char(char **a, int y)
{
	int	i;

	i = 0;
	while (i < y)
		free(a[i++]);
	free(a);
	a = NULL;
}

void	free2d_int(int **a, int y)
{
	int	i;

	i = 0;
	while (i < y)
		free(a[i++]);
	free(a);
	a = NULL;
}

t_pos	find_player(char **map)
{
	t_pos	pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
			if (map[pos.y][pos.x] == 'N' || map[pos.y][pos.x] == 'S'
				|| map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'W')
				return (pos);
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}
