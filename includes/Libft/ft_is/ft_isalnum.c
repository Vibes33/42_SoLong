/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:03:09 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 09:44:58 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// int    main(int argc, char **argv)
// {
// 	(void) argc;
//    int    i;
//    i = 0;
//    while (argv[1][i])
//    {
// 	   if (ft_isalnum(argv[1][i]))
// 		   printf("'%c' est alphanumérique\n", argv[1][i]);
// 	   else
// 		   printf("'%c' \n", argv[1][i]);
// 	   i++;
//    }
//    return (0);
// }
