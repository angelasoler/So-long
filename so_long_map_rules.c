/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_rules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:22:36 by asoler            #+#    #+#             */
/*   Updated: 2022/07/18 16:20:51 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	different_characters(char *line)
{
	while (*line)
	{
		if (*line != 'C' && *line != 'E' && *line != 'P' && \
		*line != '0' && *line != '1')
			return (1);
		line++;
	}
	return (0);
}

int	wall_sorrounded(t_map *read_map)
{
	int	x;
	int	y;
	int	y_backup;
	int	x_backup;

	x = read_map->x - 1;
	y = read_map->height - 1;
	x_backup = x;
	y_backup = y;
	while (y_backup >= 0)
	{
		if (read_map->map[y_backup][0] != '1' || \
		read_map->map[y_backup][x_backup] != '1')
			return (1);
		y_backup--;
	}
	while (x >= 0)
	{
		if (read_map->map[0][x] != '1' || read_map->map[y][x] != '1')
			return (1);
		x--;
	}
	return (0);
}

int	verify_map(t_map *read_map)
{
	int	characters[3];
	int	i;

	i = 0;
	ft_bzero(characters, (sizeof(int) * 3));
	while (read_map->map[i])
	{
		if ((ft_strlen(read_map->map[i]) != (size_t)read_map->x) || \
		different_characters(read_map->map[i]) || wall_sorrounded(read_map))
			return (1);
		if (ft_strchr(read_map->map[i], 'C'))
			characters[0]++;
		if (ft_strchr(read_map->map[i], 'P'))
			characters[1]++;
		if (ft_strchr(read_map->map[i], 'E'))
			characters[2]++;
		i++;
	}
	if (!characters[0] || characters[1] != 1 || characters[2] != 1)
		return (1);
	return (0);
}

int	verify_map_file_type(char *map_argument)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_argument);
	type = ft_strnstr(map_argument, ".ber", len);
	if (!type || (*(type + 4) != '\0'))
		return (1);
	return (0);
}
