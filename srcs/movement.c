/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:00:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 18:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	can_move(t_data *data, int new_y, int new_x)
{
	char	tile;

	if (new_y < 0 || new_y >= data->map->height)
		return (0);
	if (new_x < 0 || new_x >= data->map->width)
		return (0);
	tile = data->map->map[new_y][new_x];
	if (tile == '1')
		return (0);
	return (1);
}

static void	collect_item(t_data *data, int y, int x)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->player->coins++;
		data->map->collnb--;
	}
}

static void	check_exit(t_data *data, int y, int x)
{
	if (data->map->map[y][x] == 'E' && data->map->collnb == 0)
		kill_prog(data);
}

void	move_player(t_data *data, int dy, int dx)
{
	int	new_y;
	int	new_x;

	new_y = data->player->pos[0] + dy;
	new_x = data->player->pos[1] + dx;
	if (dx == -1)
		data->player->dir = LEFT;
	else if (dx == 1)
		data->player->dir = RIGHT;
	if (!can_move(data, new_y, new_x))
		return ;
	data->player->pos[0] = new_y;
	data->player->pos[1] = new_x;
	data->player->move_nbr++;
	ft_printf("%d\n", data->player->move_nbr);
	collect_item(data, new_y, new_x);
	check_exit(data, new_y, new_x);
	render_map(data);
}
