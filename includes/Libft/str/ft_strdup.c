/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:16:39 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 12:56:34 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
	{
		return (NULL);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int    main(int argc, char **argv)
// {
//    char    *dup;
// 	(void)argc;

//    dup = ft_strdup(argv[1]);
//    printf("Chaîne originale : \"%s\"\n", argv[1]);
//    printf("Chaîne dupliquée : \"%s\"\n", dup);
//    free(dup);
//    return (0);
// }
