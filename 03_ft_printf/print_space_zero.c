/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:46:07 by jwon              #+#    #+#             */
/*   Updated: 2020/05/03 13:33:34 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space_diuxp(t_info *info, long long data)
{
	int				idx;

	idx = data < 0 ? 1 : 0;
	if (info->zero && !info->dot && !info->prec)
		idx += (info->width - info->data_len);
	if (info->spec == 'p')
		idx += 2;
	if (info->data_len < info->prec)
		while (idx++ < (info->width - info->prec))
			ft_putchar(' ', info);
	else
		while (idx++ < (info->width - info->data_len))
			ft_putchar(' ', info);
}

void		print_zero_diuxp(t_info *info, long long data)
{
	int				idx;

	if (info->zero && !info->dot && !info->prec)
	{
		idx = data < 0 ? 1 : 0;
		while (idx++ < info->width - info->data_len)
			ft_putchar('0', info);
	}
	else if (info->data_len < info->prec)
	{
		idx = 0;
		while (idx++ < info->prec - info->data_len)
			ft_putchar('0', info);
	}
}

void		print_space_sc(t_info *info)
{
	int				idx;

	if (info->zero && !info->align && !info->dot && !info->prec)
		return ;
	idx = 0;
	if (info->prec && info->prec < info->data_len)
		while (idx++ < (info->width - info->prec))
			ft_putchar(' ', info);
	else if (!info->zero && info->data_len < info->width)
		while (idx++ < (info->width - info->data_len))
			ft_putchar(' ', info);
}

void		print_zero_sc(t_info *info)
{
	int				idx;

	idx = 0;
	if (info->zero && !info->align)
		while (idx++ < info->width - info->data_len)
			ft_putchar('0', info);
}
