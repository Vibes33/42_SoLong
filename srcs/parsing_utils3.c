/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:35:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/29 00:36:50 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_border_tile(char **map, int i, int j)
{
	return (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1]);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y])
		return ;
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
