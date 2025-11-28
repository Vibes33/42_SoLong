/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:58:28 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/21 16:03:08 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_n;

	i = 0;
	len_n = ft_strlen(little);
	if (len_n == 0)
		return ((char *)big);
	while (big[i] && i + len_n <= len)
	{
		if (ft_strncmp(big + i, little, len_n) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int    main(int argc, char **argv)
// {
// 	(void)argc;
//   char    *res;
//    char    *haystack;
//    char    *needle;
//    size_t    len;
//    haystack = argv[1];
//    needle = argv[2];
//    len = (size_t)atoi(argv[3]);
//    res = ft_strnstr(haystack, needle, len);
//   printf("%s", res);
// }
