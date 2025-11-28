/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:59:51 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 13:46:40 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}

// int    main(int argc, char **argv)
// {
// 	(void)argc;
//    char    *res;
//    char    *str;
//    char    c;
//    str = argv[1];
//    c = argv[2][0];
//    res = ft_strrchr(str, c);
//    if (res)
//        printf("Dernière occurrence de '%c' trouvée : \"%s\"\n", c, res);
//    else
//        printf("Caractère '%c' non trouvé dans \"%s\".\n", c, str);
//    return (0);
// }
