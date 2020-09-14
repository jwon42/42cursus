/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:37:41 by jwon              #+#    #+#             */
/*   Updated: 2020/09/14 17:35:59 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace_str(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (ft_isspace(str[idx]))
			idx++;
		else
			return (0);
	}
	return (1);
}
