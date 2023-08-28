/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:58:44 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 13:50:40 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkmapcub(char *s)
{
	int	i;

	if (ft_strlen(s) > 4)
	{
		i = ft_strlen(s) - 1;
		if (s[i] == 'b' && s[i - 1] == 'u'
			&& s[i - 2] == 'c' && s[i - 3] == '.')
			return (0);
	}
	return (-1);
}

int	checkmapchar(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] >= 9 && map[i][j] <= 13)
				map[i][j] = ' ';
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (-1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				flag++;
		}
	}
	if (flag != 1)
		return (-1);
	return (0);
}
