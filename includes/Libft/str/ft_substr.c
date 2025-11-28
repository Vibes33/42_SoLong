/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:11 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 13:54:33 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int    main(int argc, char **argv)
// {
//    char    *res;
//    size_t    start;
//   size_t    len;
//   (void) argc;

//    start = (size_t)atoi(argv[2]);
//    len = (size_t)atoi(argv[3]);
//   res = ft_substr(argv[1], start, len);

//    printf("Résultat après ft_substr : \"%s\"\n", res);
//    free(res);
//    return (0);
// }
