/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 08:41:46 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 10:29:32 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	visited_close(int **visited, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = -1;
		while (++j < x)
			if (i == 0 || i + 1 == y || j == 0 || j + 1 == x)
				visited[i][j] = 1;
		i++;
	}
}

static int	**visited_map(char **map, int **visited)
{
	int	i;
	int	j;

	i = 0;
	if (!visited || !*visited)
		return (NULL);
	visited_close(visited, array2d_y(map) + 2, ft_strlen(map[0]) + 2);
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '1')
				visited[i + 1][j + 1] = 1;
		i++;
	}
	return (visited);
}

int	**init_visited(char **map)
{
	int		**visited;
	int		n;
	int		i;
	int		len;

	if (!map || !*map)
		return (NULL);
	i = -1;
	len = ft_strlen(map[0]);
	n = array2d_y(map);
	visited = malloc((n + 3) * sizeof(int *));
	if (!visited)
		return (NULL);
	while (++i < n + 2)
	{
		visited[i] = ft_calloc(len + 2, sizeof(int));
		if (!visited[i])
		{
			free2d_int(visited, i);
			return (NULL);
		}
	}
	visited[i] = NULL;
	return (visited_map(map, visited));
}
