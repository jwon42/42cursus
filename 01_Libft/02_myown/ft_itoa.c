/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:41:54 by jwon              #+#    #+#             */
/*   Updated: 2020/04/10 22:18:33 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int				idx;
	int				size;
	char			tmp;

	size = ft_strlen(str);
	idx = 0;
	while (idx < (size / 2))
	{
		tmp = str[idx];
		str[idx] = str[size - idx - 1];
		str[size - idx - 1] = tmp;
		idx++;
	}
	return (str);
}

int			ft_intlen(int n)
{
	int				idx;
	long long		tmp;

	tmp = n;
	idx = 1;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		idx++;
	}
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		idx++;
	}
	return (idx);
}

char		*ft_itoa(int n)
{
	int				idx;
	int				is_negative;
	unsigned int	positive_n;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
		return (NULL);
	ft_memset(value, '\0', (ft_intlen(n) + 1));
	is_negative = n < 0 ? 1 : 0;
	positive_n = n < 0 ? -n : n;
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	if (is_negative)
		value[idx++] = '-';
	return (ft_strrev(value));
}
