/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:43:48 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 13:07:53 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void    to_uppercase(unsigned int i, char *c)
// {
//    (void)i;
//    if (*c >= 'a' && *c <= 'z')
//        *c -= 32;
// }

// int    main(int argc, char **argv)
// {
// 	(void)argc;
//    char    *str;
//    str = ft_strdup(argv[1]);
//    printf("Avant ft_striteri : %s\n", str);
//    ft_striteri(str, to_uppercase);
//    printf("Après ft_striteri : %s\n", str);
//    free(str);
//    return (0);
// }
