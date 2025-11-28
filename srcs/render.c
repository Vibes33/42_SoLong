/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:00:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 17:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	*load_xpm(t_data *data, char *path)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		put_err("Malloc error", data);
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->w, &img->h);
	if (!img->img)
	{
		free(img);
		ft_putstr_fd("Failed to load: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		put_err("Failed to load sprite", data);
	}
	return (img);
}

void	load_sprites(t_data *data)
{
	data->map->floor = load_xpm(data, SPRITE_FLOOR);
	data->map->wall = load_xpm(data, SPRITE_WALL);
	data->map->coll = load_xpm(data, SPRITE_COLL);
	data->map->c_exit = load_xpm(data, SPRITE_EXIT);
	data->player->sprite_r = load_xpm(data, SPRITE_PLAYER_R);
	data->player->sprite_l = load_xpm(data, SPRITE_PLAYER_L);
}

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
