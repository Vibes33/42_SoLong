/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:01:33 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:02:06 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	put_err(char *err_mess, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_mess, 2);
	ft_putstr_fd("\n", 2);
	if (data)
		free_all(data);
	exit(1);
}

