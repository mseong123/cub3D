/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:11:26 by lewlee            #+#    #+#             */
/*   Updated: 2023/08/28 14:11:27 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnljoin(char *str1, char *str2)
{
	int		i;
	int		len1;
	char	*r_str;

	i = 0;
	len1 = ft_strlen(str1);
	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	r_str = (char *)malloc((len1 + ft_strlen(str2) + 1) * sizeof(char));
	if (!r_str)
	{
		free(str1);
		return (NULL);
	}
	while (i++ < len1)
		r_str[i - 1] = str1[i - 1];
	i = 0;
	while (str2[i++])
		r_str[i - 1 + len1] = str2[i - 1];
	r_str[i - 1 + len1] = '\0';
	free(str1);
	return (r_str);
}

char	**get_cub(int fd)
{
	int		i;
	char	*temp;
	char	*r_str;
	char	**r_arr;

	i = 0;
	temp = get_next_line(fd);
	r_str = NULL;
	while (temp)
	{
		if (!r_str)
			r_str = temp;
		else
		{
			r_str = gnljoin(r_str, temp);
			free(temp);
		}
		temp = get_next_line(fd);
	}
	r_arr = ft_split(r_str, '\n');
	free(r_str);
	if (!r_arr)
		return (NULL);
	return (r_arr);
}

char	**get_file(char *filename)
{
	int		fd;
	char	**file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = get_cub(fd);
	return (file);
}
