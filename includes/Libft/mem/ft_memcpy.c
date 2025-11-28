/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:29 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 12:34:26 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}

// int	 main(int argc, char **argv)
// {
// 	size_t	 n;
// 	char *result;
// 	(void)argc;
// 	n = (size_t)atoi(argv[3]);
// 	result = ft_memcpy(argv[1],argv[2], n );
// 	printf("%s",result);
// }
