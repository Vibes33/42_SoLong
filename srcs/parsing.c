/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:00:04 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:06 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_acces(char **map)
{
	int		i;
	int		j;
	int		spawn[2];
	char	**dup;

	find_firstof(map, 'P', spawn);
	dup = clone_map(map);
	flood_fill(dup, spawn[0], spawn[1]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("CE", dup[i][j]))
			{
				big_big_free(map);
				big_big_free(dup);
				put_err("Map elements aren't all reachable", NULL);
			}
		}
	}
	big_big_free(dup);
}

static void	elements_check(char **map, int x, int y)
{
	int	map_e[4];

	while (x < 4)
		map_e[x++] = 0;
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			map_e[0] += map[x][y] == 'C';
			map_e[1] += map[x][y] == 'E';
			map_e[2] += map[x][y] == 'P';
			map_e[3] += !ft_strchr("01CEP", map[x][y]);
		}
	}
	if (map_e[0] == 0 || map_e[1] != map_e[2] || map_e[1] != 1 || map_e[3])
	{
		big_big_free(map);
		put_err("Wrong elem/number of elem in map (2P, 2E or 0C)", NULL);
	}
}

static char	**get_map(char *file_name)
{
	int		fd;
	char	*line;
	char	*raw_map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		put_err("Cannot open map file", NULL);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		put_err("Empty map submitted", NULL);
	}
	raw_map = ft_strdup(line);
	if (!raw_map)
		put_err("Malloc error", NULL);
	free(line);
	line = get_next_line(fd);
	continue_parsing(&line, fd, &raw_map);
	return (check_empty_line_split(raw_map));
}

static void	border_check(char **map)
{
	int		i;
	int		j;
	size_t	first_len;

	if (!map || !map[0])
		put_err("Empty map", NULL);
	first_len = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != first_len)
		{
			big_big_free(map);
			put_err("Map is not rectangular", NULL);
		}
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
				&& map[i][j] != '1')
			{
				big_big_free(map);
				put_err("Map is not surrounded by walls", NULL);
			}
		}
	}
}

char	**get_and_parse(char *file_name)
{
	char	**map;

	map = NULL;
	if (ft_strrchr(file_name, '.') && \
		ft_strncmp(ft_strrchr(file_name, '.'), ".ber", 5) == 0)
	{
		map = get_map(file_name);
		border_check(map);
		elements_check(map, 0, 0);
		check_acces(map);
	}
	else
		put_err("Invalid map name (must be .ber)", NULL);
	return (map);
}