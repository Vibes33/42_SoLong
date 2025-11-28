/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:22 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 09:11:12 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *) &ptr[i]);
		}
		i++;
	}
	return (NULL);
}

//int    main(int argc, char **argv)
//{
//   char    *str;
//    char    c;
//size_t    n;
//    void    *res;
//
//    if (argc != 4)
//    {
//        printf("Usage: %s <string> <char_to_find> <n>\n", argv[0]);
//        return (1);
//    }
//    str = argv[1];
//    c = argv[2][0];
//    n = (size_t)atoi(argv[3]);
//    res = ft_memchr(str, c, n);
//    if (res)
//        printf("Caractère '%c' trouvé à la position : %ld\n", c,
//            (long)((unsigned char *)res - (unsigned char *)str));
//    else
//        printf("Caractère '%c' non trouvé", c);
//    return (0);
//}
