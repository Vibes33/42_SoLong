/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:24:31 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/21 15:45:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

//int    main(int argc, char **argv)
//{
//   size_t    len;
//
//   if (argc != 2)
//   {
//        printf("Usage: %s <string>\n", argv[0]);
//        printf("Exemple: %s \"Hello World\"\n", argv[0]);
//        return (1);
//    }
//    len = ft_strlen(argv[1]);
//    printf("Chaîne : \"%s\"\n", argv[1]);
//    printf("Longueur calculée par ft_strlen : %zu\n", len);
//    return (0);
//}
