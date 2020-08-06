/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:06:25 by jwon              #+#    #+#             */
/*   Updated: 2020/05/06 23:02:06 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c, t_info *info)
{
	write(1, &c, 1);
	info->printed_len++;
}

void		ft_putstr(char *s, t_info *info)
{
	int			idx;

	if (!s || (info->spec == 's' && info->dot == 1 && info->prec == 0))
		return ;
	idx = 0;
	if (info->spec == 's' && info->prec)
		while (s[idx] && idx < info->prec)
			ft_putchar(s[idx++], info);
	else
		while (s[idx])
			ft_putchar(s[idx++], info);
}

void		ft_putnbr_base(long long n, char *base, t_info *info)
{
	int			notation;

	if (n == 0 && info->dot && !info->prec)
		return ;
	notation = ft_strlen(base, info);
	if (n >= notation)
		ft_putnbr_base((n / notation), base, info);
	ft_putchar(base[n % notation], info);
}

int			ft_strlen(char *str, t_info *info)
{
	int			idx;

	if (str == NULL || (info->spec == 's' && info->dot && !info->prec))
		return (0);
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int			ft_nbrlen_base(long long n, char *base, t_info *info)
{
	int			idx;
	int			notation;

	if (n == 0 && info->dot && !info->prec)
		return (0);
	notation = ft_strlen(base, info);
	idx = 1;
	while (n >= notation)
	{
		n /= notation;
		idx++;
	}
	return (idx);
}
