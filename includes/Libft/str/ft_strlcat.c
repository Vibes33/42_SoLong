/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:19:53 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/21 15:48:22 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(dst);
	index = 0;
	while (dst[index])
		index++;
	i = 0;
	while (src[i] && (i + index + 1) < (size))
	{
		dst[index + i] = src[i];
		i++;
	}
	if (i < size)
		dst[index + i] = '\0';
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dst_len);
}

// int    main(int argc, char **argv)
// {
//    char    dest[100];
//    char    *src;
//    size_t    size;
//    size_t    ret;
//    (void)argc;
//    ft_strlcpy(dest, argv[1], sizeof(dest));
//    src = argv[2];
//    size = (size_t)atoi(argv[3]);
//    ret = ft_strlcat(dest, src, size);
//    printf("Destination initiale : \"%s\"\n", argv[1]);
//    printf("Source : \"%s\"\n", src);
//    printf("Taille donnée : %zu\n", size);
//    printf("Résultat après ft_strlcat : \"%s\"\n", dest);
//    return (0);
// }
