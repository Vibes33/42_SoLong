/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:57:54 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 13:33:37 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
//int    main(int argc, char **argv)
//{
//    char    *res;
//    res = ft_strmapi(argv[1], ft_tolower);

//    printf("Avant ft_strmapi : %s\n", argv[1]);
//    printf("Après ft_strmapi : %s\n", res);
//    free(res);
//    return (0);
//}
