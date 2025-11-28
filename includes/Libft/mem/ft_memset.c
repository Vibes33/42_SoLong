/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:05:48 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 12:34:18 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int    main(int argc, char **argv)
// {
//    char    buffer[100];
//    int        c;
//    size_t    n;
//    size_t    i;
//    (void)argc;
//    c = argv[1][0];
//    n = (size_t)atoi(argv[2]);
//    if (n > sizeof(buffer))
//       n = sizeof(buffer);
//    ft_memset(buffer, c, n);
//   printf("Buffer après ft_memset('%c', %zu) :\n", c, n);
//   i = 0;
//   while (i < n)
//   {
//        printf("%c", buffer[i]);
//        i++;
//    }
//    printf("\n");
//    return (0);
// }
