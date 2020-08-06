/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf(checknorm).c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:03:38 by jwon              #+#    #+#             */
/*   Updated: 2020/05/30 18:28:36 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define DEC "0123456789"
#define HEX "0123456789abcdef"

typedef struct	s_info
{
	int			width;
	int			dot;
	int			prec;
	int			spec;
	int			data_len;
	int			printed_len;
}				t_info;

int				ft_strlen(char *str, t_info *info)
{
	int			idx;

	idx = 0;
	if (info->spec == 's' && info->dot == 1 && info->prec == 0)
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

int				ft_nbrlen(long long n, char *base, t_info *info)
{
	int			idx;
	int			notation;

	if (n == 0 && info->dot == 1 && info->prec == 0)
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

void			ft_putchar(char c, t_info *info)
{
	write(1, &c, 1);
	info->printed_len++;
}

void			ft_putstr(char *s, t_info *info)
{
	int			idx;

	idx = 0;
	if (info->dot == 1 && info->prec == 0)
		return ;
	if (info->prec)
		while (s[idx] && idx < info->prec)
			ft_putchar(s[idx++], info);
	else
		while (s[idx])
			ft_putchar(s[idx++], info);
}

void			ft_putnbr(long long n, char *base, t_info *info)
{
	int			notation;

	if (n == 0 && info->dot == 1 && info->prec == 0)
		return ;
	notation = ft_strlen(base, info);
	if (n >= notation)
		ft_putnbr((n / notation), base, info);
	ft_putchar(base[n % notation], info);
}

void			print_space_zero(t_info *info)
{
	int			count_space;
	int			count_zero;

	count_space = 0;
	count_zero = 0;
	if (info->spec == 's')
	{
		count_space = (info->prec && info->prec < info->data_len)
			? info->width - info->prec : info->width - info->data_len;
	}
	else
	{
		count_space = (info->data_len < info->prec)
			? info->width - info->prec : info->width - info->data_len;
		count_zero = info->prec - info->data_len;
	}
	while (0 < count_space--)
		ft_putchar(' ', info);
	while (0 < count_zero--)
		ft_putchar('0', info);
}

void			print_sdx(va_list ap, t_info *info)
{
	char		*base;
	char		*data_s;
	long long	data_dx;

	if (info->spec == 's')
	{
		data_s = va_arg(ap, char *);
		data_s = (data_s == NULL) ? "(null)" : data_s;
		info->data_len = ft_strlen(data_s, info);
		print_space_zero(info);
		ft_putstr(data_s, info);
	}
	else
	{
		base = info->spec == 'd' ? DEC : HEX;
		info->spec == 'd' ? (data_dx = va_arg(ap, int))
			: (data_dx = va_arg(ap, unsigned int));
		info->data_len = (data_dx < 0) ? ft_nbrlen(-data_dx, base, info)
			: ft_nbrlen(data_dx, base, info);
		print_space_zero(info);
		data_dx < 0 ? ft_putchar('-', info) : 0;
		data_dx < 0 ? ft_putnbr(-data_dx, base, info)
					: ft_putnbr(data_dx, base, info);
	}
}

void			parse_info(const char **str, t_info *info)
{
	while (**str >= '0' && **str <= '9')
	{
		info->width = info->width * 10 + **str - '0';
		(*str)++;
	}
	if (**str == '.')
	{
		info->dot = 1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		info->prec = info->prec * 10 + **str - '0';
		(*str)++;
	}
	if (**str == 's' || **str == 'd' || **str == 'x')
		info->spec = **str;
}

void			init(t_info *info)
{
	info->width = 0;
	info->dot = 0;
	info->prec = 0;
	info->spec = 0;
	info->data_len = 0;
}

void			control_center(va_list ap, const char *str, t_info *info)
{
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			parse_info(&str, info);
			print_sdx(ap, info);
			str++;
		}
		else
		{
			ft_putchar(*str, info);
			str++;
		}
		init(info);
	}
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_info		*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	va_start(ap, str);
	info->printed_len = 0;
	init(info);
	control_center(ap, str, info);
	free(info);
	va_end(ap);
	return (info->printed_len);
}
