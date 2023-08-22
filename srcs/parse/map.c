#include "cub3d.h"

void	parse_map(t_data *data)
{
	char	*line;
	char	*file;
	char	*temp;
	int		fd;

	fd = open("./assets/map.cub",O_RDONLY);
	line = get_next_line(fd);
	file = ft_calloc(1, sizeof(char));
	while (line && file)
	{
		temp = file;
		file = ft_strjoin(file, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	free(line);
	data->map = ft_split(file, '\n');
	free(file);
}