/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:25 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 12:34:29 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s10;
	const unsigned char		*s20;
	int						sum;

	s10 = (const unsigned char *)s1;
	s20 = (const unsigned char *)s2;
	sum = 0;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*s10 != *s20)
		{
			sum = (int)(*s10 - *s20);
			return (sum);
		}
		s10++;
		s20++;
	}
	return (0);
}

// int    main(int argc, char **argv)
// {
// 	(void)argc;
//    int        result;
//    size_t    n;
//    n = (size_t)atoi(argv[3]);
//    result = ft_memcmp(argv[1], argv[2], n);
//    printf("result : %d",result );
//    return (0);
// }
