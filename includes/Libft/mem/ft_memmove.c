/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:32 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/23 15:17:46 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*data_dst;
	char	*data_src;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		data_dst = (char *)dst;
		data_src = (char *)src;
		while (len--)
			data_dst[len] = data_src[len];
	}
	return (dst);
}

// int	 main(int argc, char **argv)
// {
// 	size_t	 n;
// 	char *result;	
// 	(void)argc;
// 	n = (size_t)atoi(argv[3]);
// 	result = ft_memmove(argv[1],argv[2], n );
// 	printf("%s",result);
// } 
