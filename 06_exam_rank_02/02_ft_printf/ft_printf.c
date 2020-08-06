/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:03:38 by jwon              #+#    #+#             */
/*   Updated: 2020/06/02 17:20:43 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> // va_list, va_arg, va_start, va_end
#include <unistd.h> // write

#define NOTATION ((spec == 'd') ? 10 : 16) // 진법 정의, d면 10진법 x면 16진법
#define BASE ((spec == 'd') ? "0123456789" : "0123456789abcdef") // 진법에 사용할 문자 정의

int 	width; // 길이
int		dot; // [.]
int		prec; // 정밀도
int 	spec; // 서식지정자
int		data_len; // 출력할 인자의 길이
int 	printed_len; // 출력된 총 글자수

int			ft_strlen(char *str)
{
	int			idx = 0;

	if (spec == 's' && dot == 1 && prec == 0) // 예외처리
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

int			ft_nbrlen(long long n) // base(진법) 기반 길이 측정
{
	int			idx = 1;

	if (n == 0 && dot == 1 && prec == 0) // 예외처리
		return (0);
	while (n >= NOTATION)
	{
		n /= NOTATION;
		idx++;
	}
	return (idx);
}

void		ft_putchar(char c) // 글자 출력, 출력값 계산
{
	write(1, &c, 1);
	printed_len++;
}

void		ft_putstr(char *s)
{
	int			idx = 0;

	if (dot == 1 && prec == 0) // 예외처리
		return ;
	if (prec) // 정밀도가 있으면
		while (s[idx] && idx < prec) // 정밀도까지만 출력
			ft_putchar(s[idx++]);
	else
		while (s[idx])
			ft_putchar(s[idx++]);
}

void		ft_putnbr(long long n) // base(진법) 기반 숫자 출력
{
	if (n == 0 && dot == 1 && prec == 0) // 예외처리
		return ;
	if (n >= NOTATION)
		ft_putnbr(n / NOTATION);
	ft_putchar(BASE[n % NOTATION]);
}

void		print_space_zero(void)
{
	int				count_space = 0; // 출력할 space 의 개수
	int				count_zero = 0; // 출력할 zero 의 개수

	if (spec == 's') // 서식지정자 [%s]일 때 space 길이 계산
		count_space = (prec && prec < data_len) ? width - prec : width - data_len;
	else // 서식지정자 [%d], [%x] 일 때 space, zero 길이 계산
	{
		count_space = (data_len < prec) ? width - prec : width - data_len;
		count_zero = prec - data_len;
	}
	while (0 < count_space--) // 계산된 space 길이만큼 [' '] 출력
		ft_putchar(' ');
	while (0 < count_zero--) // 계산된 zero 길이만큼 ['0'] 출력
		ft_putchar('0');
}

void		print_sdx(va_list ap)
{
	char			*data_s;
	long long		data_dx;

	if (spec == 's')
	{
		data_s = va_arg(ap, char *);
		data_s = (data_s == NULL) ? "(null)" : data_s;
		data_len = ft_strlen(data_s);
		print_space_zero();
		ft_putstr(data_s);
	}
	else
	{
		spec == 'd' ? (data_dx = va_arg(ap, int)) : (data_dx = va_arg(ap, unsigned int));
		data_len = (data_dx < 0) ? (int)ft_nbrlen(-data_dx) : ft_nbrlen(data_dx);
		print_space_zero();
		data_dx < 0 ? ft_putchar('-') : 0; // 음수면 ['-'] 출력
		data_dx < 0 ? ft_putnbr(-data_dx) : ft_putnbr(data_dx); // 음수면 ['-']를 이미 출력했기에 양수로 변환해서 putnbr에 보냄
	}
}

void		parse_info(const char **str) // % 다음글자부터 서식지정자까지 정보 분석
{
	while ('0' <= **str && **str <= '9')
	{
		width = width * 10 + **str - '0';
		(*str)++;
	}
	if (**str == '.')
	{
		dot = 1;
		(*str)++;
	}
	while ('0' <= **str && **str <= '9')
	{
		prec = prec * 10 + **str - '0';
		(*str)++;
	}
	if (**str == 's' || **str == 'd' || **str == 'x')
		spec = **str;
}

void		init() // 정보 초기화
{
	width = 0;
	dot = 0;
	prec = 0;
	spec = 0;
	data_len = 0;
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	printed_len = 0;
	while (*str) // str 끝까지 반복
	{
		if (*str == '%') // % 라면 서식지정자까지 정보 저장 후 출력
		{
			++str;
			parse_info(&str);
			print_sdx(ap);
			str++;
		}
		else // % 아니면 한글자씩 출력
		{
			ft_putchar(*str);
			str++;
		}
		init();
	}
	va_end(ap);
	return (printed_len);
}
