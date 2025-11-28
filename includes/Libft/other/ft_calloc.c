/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:09:56 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/20 09:12:12 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

//int    main(int argc, char **argv)
//{
//    size_t    count;
//    size_t    size;
//    char    *ptr;
//    size_t    i;
//    count = (size_t)atoi(argv[1]);
//    size = (size_t)atoi(argv[2]);
//    ptr = (char *)ft_calloc(count, size);
//    if (!ptr)
//    {
//        printf("Allocation échouée\n");
//       return (1);
//   }
//    printf("Mémoire allouée (%zu * %zu = %zu octets):\n", 
// count, size, count * size);
//    i = 0;
//    while (i < count * size)
//    {
//        printf("%d ", ptr[i]);
//        i++;
//    }
//    printf("\n");
//    free(ptr);
//    return (0);
//}
