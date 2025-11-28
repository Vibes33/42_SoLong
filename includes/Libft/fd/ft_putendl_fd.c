/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:49:40 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/23 14:45:18 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

//int    main(int argc, char **argv)
//{
//	(void)argc;
//    int    fd;
//   fd = atoi(argv[2]);
//   ft_putendl_fd(argv[1], fd);
//  return (0);
//}