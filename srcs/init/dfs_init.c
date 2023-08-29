/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 08:34:49 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/29 11:20:12 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_mapjoin(char *maprow, int type)
{
	char	*newrow;
	int		i;

	i = -1;
	newrow = malloc((ft_strlen(maprow) + 3) * sizeof(char));
	if (!newrow)
		return (NULL);
	if (type == 1)
	{
		newrow[0] = ' ';
		while (maprow[++i])
			newrow[i + 1] = maprow[i];
		newrow[i + 1] = ' ';
		i += 2;
	}
	else
		while (++i <= (int)ft_strlen(maprow) + 1)
			newrow[i] = ' ';
	newrow[i] = '\0';
	return (newrow);
}

static char	**modify_map(char **map)
{
	int		i;
	char	**newmap;
	int		len;

	i = -1;
	len = array2d_y(map) + 3;
	newmap = malloc(len * sizeof(char *));
	if (!newmap)
		return (NULL);
	newmap[0] = ft_mapjoin(map[0], 0);
	while (map[++i])
	{
		newmap[i + 1] = ft_mapjoin(map[i], 1);
		if (!newmap[i + 1])
		{
			free2d_char(newmap, i + 1);
			return (NULL);
		}
	}
	newmap[i + 1] = ft_mapjoin(map[0], 0);
	newmap[i + 2] = NULL;
	return (newmap);
}

void	dfs_init(t_map *map_dfs, t_data *data)
{
	if (!data->map || !*data->map)
		exit (write(2, "Error\nFailed ", 14) - write(2, "to load map\n", 13));
	map_dfs->map = modify_map(data->map);
	if (!map_dfs->map | !*map_dfs->map)
		exit (write(2, "Error\nFailed ", 14) - write(2, "to load map\n", 13));
	map_dfs->start.x = 0;
	map_dfs->start.y = 0;
	map_dfs->max.x = ft_strlen(map_dfs->map[0]);
	map_dfs->max.y = array2d_y(map_dfs->map);
	map_dfs->flag = ft_calloc(1, sizeof(int));
	if (!map_dfs->flag)
	{
		free2d_char(map_dfs->map, map_dfs->max.y);
		exit (write(2, "Error\nFailed", 13) - write(2, " to init DFS\n", 14));
	}
	map_dfs->visited = init_visited(map_dfs->map);
	if (!map_dfs->visited)
	{
		free2d_char(map_dfs->map, map_dfs->max.y);
		exit (write(2, "Error\nFailed", 13) - write(2, " to init DFS\n", 14));
		return ;
	}
}
