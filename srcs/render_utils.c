/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:35:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 21:47:29 by rydelepi         ###   ########.fr       */
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
