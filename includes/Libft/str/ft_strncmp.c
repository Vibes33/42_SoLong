/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:21:59 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/23 15:28:25 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((!s1[i] || !s2[i]) && i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
// int    main(int argc, char **argv)
// {
//    int        result;
//    size_t    n;
// 	(void) argc;
//    n = (size_t)atoi(argv[3]);
//    result = ft_strncmp(argv[1], argv[2], n);

//    printf("resultat : %d",result);
//    return (0);
// }
