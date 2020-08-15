/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:07:07 by jwon              #+#    #+#             */
/*   Updated: 2020/08/15 13:07:50 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_compare(char *str1, char *str2)
{
	while (*str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			if (str_compare(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
