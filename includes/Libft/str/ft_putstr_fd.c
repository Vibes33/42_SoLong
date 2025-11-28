/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:40:48 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/17 09:04:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

//int    main(int argc, char **argv)
//{
//    int    fd;
//
//    if (argc != 3)
//    {
//        printf("Usage: %s <string> <fd>\n", argv[0]);
//        printf("Exemple: %s \"Hello World\" 1\n", argv[0]);
//        return (1);
//    }
//    fd = atoi(argv[2]);
//    ft_putstr_fd(argv[1], fd);
//    ft_putstr_fd("\n", fd);
//    return (0);
//}
