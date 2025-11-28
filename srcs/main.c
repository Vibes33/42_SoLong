/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:29:52 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 13:29:56 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	input(int key, t_data *data)
{
	if (key == ESC)
		kill_prog(data);
	else if (key == KEY_W || key == KEY_UP)
		move_player(data, -1, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(data, 1, 0);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(data, 0, -1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(data, 0, 1);
	return (0);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->player = NULL;
	return (data);
}

static void	init_map_data(t_data *data, char **map)
{
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
		put_err("Malloc error", data);
	data->map->map = map;
	data->map->width = map_width(map);
	data->map->height = map_height(map);
	find_firstof(map, 'P', data->map->spawn);
	find_firstof(map, 'E', data->map->p_exit);
	data->map->collnb = number_of(map, 'C');
	data->player = ft_calloc(sizeof(t_player), 1);
	if (!data->player)
		put_err("Malloc error", data);
	data->player->pos[0] = data->map->spawn[0];
	data->player->pos[1] = data->map->spawn[1];
	data->player->coins = 0;
	data->player->move_nbr = 0;
	data->player->dir = RIGHT;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**map;

	if (argc != 2)
		put_err("Usage: ./so_long <map.ber>", NULL);
	data = init_data();
	if (!data)
		put_err("Malloc error", NULL);
	map = get_and_parse(argv[1]);
	if (!map)
		put_err("Invalid map", data);
	init_map_data(data, map);
	data->mlx = mlx_init();
	if (!data->mlx)
		put_err("MLX init failed", data);
	data->win = mlx_new_window(data->mlx, data->map->width * TILE_SIZE,
			data->map->height * TILE_SIZE, NAME);
	if (!data->win)
		put_err("Window creation failed", data);
	load_sprites(data);
	render_map(data);
	ft_printf("Map loaded: %dx%d\n", data->map->width, data->map->height);
	mlx_key_hook(data->win, &input, data);
	mlx_hook(data->win, 17, 1L << 17, &kill_prog, data);
	mlx_loop(data->mlx);
	return (0);
}
