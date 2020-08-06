/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:45:46 by jwon              #+#    #+#             */
/*   Updated: 2020/05/03 03:33:51 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(char **str, t_info *info)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			info->align = 1;
		if (**str == '0')
			info->zero = 1;
		(*str)++;
	}
	if (info->align && info->zero)
		info->zero = 0;
}

void		parse_width(va_list ap, char **str, t_info *info)
{
	if (**str == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			if (info->zero)
				info->zero = 0;
			info->width *= -1;
			info->align = 1;
		}
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		info->width = (info->width * 10) + **str - '0';
		(*str)++;
	}
}

void		parse_precision(va_list ap, char **str, t_info *info)
{
	if (**str == '.')
	{
		info->dot = 1;
		(*str)++;
	}
	if (**str == '*')
	{
		info->prec = va_arg(ap, int);
		if (info->prec < 0)
		{
			info->prec = 0;
			info->dot = 0;
		}
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		info->prec = (info->prec * 10) + **str - '0';
		(*str)++;
	}
}

void		parse_specifier(char **str, t_info *info)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
		**str == '%')
		info->spec = **str;
	else
		return ;
	(*str)++;
}
