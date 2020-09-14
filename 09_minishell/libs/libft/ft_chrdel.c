/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:58:03 by jwon              #+#    #+#             */
/*   Updated: 2020/06/25 21:17:05 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrdel(char const *s, char c)
{
	unsigned int	idx_s;
	unsigned int	idx_buf;
	char			*buf;

	if (!s || !(buf = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	idx_s = 0;
	idx_buf = 0;
	while (s[idx_s])
	{
		if (s[idx_s] == c)
		{
			idx_s++;
			continue ;
		}
		buf[idx_buf++] = s[idx_s++];
	}
	buf[idx_buf] = '\0';
	return (buf);
}
