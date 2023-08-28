/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:53 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 10:06:36 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid(t_map map, t_pos move)
{
	if (move.x >= 0 && move.x <= map.max.x
		&& move.y >= 0 && move.y <= map.max.y
		&& map.visited[move.y + 1][move.x + 1] != 1)
		return (1);
	return (0);
}

static void	init_moves(t_pos *moves)
{
	(&moves[0])->x = 1;
	(&moves[0])->y = 0;
	(&moves[1])->x = 0;
	(&moves[1])->y = 1;
	(&moves[2])->x = -1;
	(&moves[2])->y = 0;
	(&moves[3])->x = 0;
	(&moves[3])->y = -1;
}

int	dfs(t_map *map, t_pos move)
{
	t_pos	moves[4];
	t_pos	temp;
	int		i;

	i = -1;
	map->visited[move.y + 1][move.x + 1] = 1;
	if (map->map[move.y][move.x] == 'N' || map->map[move.y][move.x] == 'S'
		|| map->map[move.y][move.x] == 'E' || map->map[move.y][move.x] == 'W')
		*(map->flag) = 1;
	if (*(map->flag) == 1)
		return (-1);
	init_moves(moves);
	while (++i < 4)
	{
		temp.x = move.x + moves[i].x;
		temp.y = move.y + moves[i].y;
		if (is_valid(*map, temp) == 1)
			if (dfs(map, temp) == 1)
				return (1);
	}
	return (-1);
}
