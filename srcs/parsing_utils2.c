/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:00:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	has_empty_line(char *raw_map)
{
	int	i;

	i = 0;
	while (raw_map[i])
	{
		if (raw_map[i] == '\n' && raw_map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**check_empty_line_split(char *raw_map)
{
	char	**map;

	if (!raw_map)
		put_err("Empty map", NULL);
	if (has_empty_line(raw_map))
	{
		free(raw_map);
		put_err("Empty line in map", NULL);
	}
	map = ft_split(raw_map, '\n');
	free(raw_map);
	if (!map)
		put_err("Malloc error", NULL);
	return (map);
}

void	continue_parsing(char **line, int fd, char **raw_map)
{
	char	*temp;

	while (*line)
	{
		temp = ft_strjoin(*raw_map, *line);
		free(*raw_map);
		free(*line);
		if (!temp)
		{
			close(fd);
			put_err("Malloc error", NULL);
		}
		*raw_map = temp;
		*line = get_next_line(fd);
	}
	close(fd);
}
