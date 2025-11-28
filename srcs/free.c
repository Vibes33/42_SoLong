/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:59:20 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 21:32:19 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_image(void *mlx, t_img *img)
{
	if (img)
	{
		if (img->img && mlx)
			mlx_destroy_image(mlx, img->img);
		free(img);
	}
}

static void	free_map(t_data *data)
{
	if (!data->map)
		return ;
	if (data->map->wall)
		free_image(data->mlx, data->map->wall);
	if (data->map->floor)
		free_image(data->mlx, data->map->floor);
	if (data->map->coll)
		free_image(data->mlx, data->map->coll);
	if (data->map->c_exit)
		free_image(data->mlx, data->map->c_exit);
	if (data->map->o_exit)
		free_image(data->mlx, data->map->o_exit);
	if (data->map->map)
		big_big_free(data->map->map);
	free(data->map);
}

static void	free_player(t_data *data)
{
	if (!data->player)
		return ;
	if (data->player->sprite_r)
		free_image(data->mlx, data->player->sprite_r);
	if (data->player->sprite_l)
		free_image(data->mlx, data->player->sprite_l);
	free(data->player);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->player)
		free_player(data);
	if (data->map)
		free_map(data);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	if (data->mlx)
		free(data->mlx);
	free(data);
}

int	kill_prog(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}
