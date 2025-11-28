/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:35:31 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 13:37:10 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c +32;
	}
	return (c);
}

//int    main(int argc, char **argv)
//{
//    int    c;
//   c = (unsigned char)argv[1][0];
//   printf("Avant ft_tolower : '%c' (code ASCII %d)\n", c, c);
//   c = ft_tolower(c);
//   printf("Après  ft_tolower : '%c' (code ASCII %d)\n", c, c);
//   return (0);
//}
