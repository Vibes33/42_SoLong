/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:30:22 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 15:46:01 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}

// int    main(int argc, char **argv)
// {
//    char    dest[100];
//    char    *src;
//    size_t    size;
//    size_t    ret;
//    src = argv[1];
//    size = (size_t)atoi(argv[2]);
//    ret = ft_strlcpy(dest, src, size);
//    printf("Source : \"%s\"\n", src);
//    printf("Taille donnée : %zu\n", size);
//    printf("Résultat après ft_strlcpy : \"%s\"\n", dest);
//    printf("Valeur de retour : %zu\n", ret);
//    return (0);
// }
