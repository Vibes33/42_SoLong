/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:14:39 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/22 09:44:35 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int	ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**free_arr(int i, char **arr)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nbword;
	int		len;
	char	**arr;

	i = 0;
	nbword = count_word(s, c);
	arr = malloc(sizeof(char *) * (nbword + 1));
	if (!arr)
		return (NULL);
	while (i < nbword)
	{
		while (*s == c && *s)
			s++;
		len = ft_strlen_c((char *) s, c);
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return (free_arr(i, arr));
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// int    main(int argc, char **argv)
// {
//    char    **tab;
//    int        i;
//    char    *str;
//    char    sep;
// 	(void) argc;
//    str = argv[1];
//   sep = argv[2][0];
//    tab = ft_split(str, sep);
//    if (!tab)
//        return (1);
//    i = 0;
//    while (tab[i])
//   {
//       printf("%s\n", tab[i]);
//       free(tab[i]);
//       i++;
//   }
//    free(tab);
//    return (0);
// }