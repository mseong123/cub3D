/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:58:44 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/29 14:57:33 by melee            ###   ########.fr       */
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

void	init_player_orient(char c, int *flag, t_data *data)
{
	if (c == 'N')
	{
		data->ray.diry = -1;
		data->ray.planex = 0.66;
	}
	else if (c == 'E')
	{
		data->ray.dirx = 1;
		data->ray.planey = 0.66;
	}
	else if (c == 'S')
	{
		data->ray.diry = 1;
		data->ray.planex = -0.66;
	}
	else
	{
		data->ray.dirx = -1;
		data->ray.planey = -0.66;
	}
	*flag += 1;
}

int	checkmapchar(char **map, t_data *data)
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
				init_player_orient(map[i][j], &flag, data);
		}
	}
	if (flag != 1)
		return (-1);
	return (0);
}
