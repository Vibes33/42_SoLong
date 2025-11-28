/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:37:23 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/29 00:37:23 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_img(t_data *data, t_img *img, int x, int y)
{
	if (img && img->img)
		mlx_put_image_to_window(data->mlx, data->win, img->img,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile(t_data *data, int x, int y)
{
	char	tile;

	tile = data->map->map[y][x];
	put_img(data, data->map->floor, x, y);
	if (tile == '1')
		put_img(data, data->map->wall, x, y);
	else if (tile == 'C')
		put_img(data, data->map->coll, x, y);
	else if (tile == 'E' && data->map->collnb == 0)
		put_img(data, data->map->c_exit, x, y);
}

static void	render_player(t_data *data)
{
	int	x;
	int	y;

	y = data->player->pos[0];
	x = data->player->pos[1];
	if (data->player->dir == LEFT)
		put_img(data, data->player->sprite_l, x, y);
	else
		put_img(data, data->player->sprite_r, x, y);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			render_tile(data, x, y);
			x++;
		}
		y++;
	}
	render_player(data);
}
