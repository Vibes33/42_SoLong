/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:59:20 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 15:59:24 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "./libft/libft.h"
#include "../includes/so_long.h"

void	big_big_free(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

static void	free_image(void *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	free(img);
}

static void	free_map(t_data *data)
{
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

void	free_all(t_data	*data)
{
	int	i;

	if (data)
	{
		if (data->map)
			free_map(data);
		if (data->player)
		{
			i = -1;
			while (data->player->sprites[++i])
				free_image(data->mlx, data->player->sprites[i]);
			free(data->player->sprites);
			free(data->player);
		}
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_display(data->mlx);
		}
		if (data->mlx)
			free(data->mlx);
		free(data);
	}
}