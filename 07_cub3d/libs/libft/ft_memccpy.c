/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:03:04 by jwon              #+#    #+#             */
/*   Updated: 2020/04/06 16:59:57 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)dest + idx) = *((unsigned char *)src + idx);
		if (*((unsigned char *)src + idx) == (unsigned char)c)
		{
			return (dest + idx + 1);
			break ;
		}
		idx++;
	}
	return (NULL);
}
