/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:11:51 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/29 11:22:41 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	longest_row(char **file, int start)
{
	int	longest;

	if (!file || !*file)
		return (0);
	longest = ft_strlen(file[0]);
	while (file[start])
	{
		if (longest < (int)ft_strlen(file[start]))
			longest = ft_strlen(file[start]);
		start++;
	}
	return (longest);
}

static char	*maprowdup(char *str, int n)
{
	int		i;
	char	*r_str;

	i = -1;
	r_str = malloc((n + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	while (str[++i])
		r_str[i] = str[i];
	if (i < n)
		while (i < n)
			r_str[i++] = ' ';
	r_str[i] = '\0';
	return (r_str);
}

void	get_map(t_data *data, char **file, int i)
{
	int		len;
	int		j;
	char	**new_arr;
	int		longest;

	if (i == -1)
		exit (write(2, "Error\nFailed to find/fou", 25) \
		- write(2, "nd duplicate variables\n", 24));
	j = 0;
	len = array2d_y(file);
	longest = longest_row(file, i);
	new_arr = malloc(((len - i) + 1) * sizeof(char *));
	while (i < len)
	{
		new_arr[j] = maprowdup(file[i++], longest);
		if (!new_arr[j++])
		{
			write (2, "Error: Failed to get map\n", 26);
			exit (1);
		}
	}
	new_arr[j] = NULL;
	free2d_char(file, len);
	data->map = new_arr;
}
