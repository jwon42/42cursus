/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:22:15 by jwon              #+#    #+#             */
/*   Updated: 2020/05/26 23:21:16 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_ascii(char *s, int *ascii)
{
	int		idx = 0;

	while (s[idx])
	{
		ascii[(int)s[idx]]++;
		idx++;
	}
}

void	print_parameter(char *s, int *ascii)
{
	int		idx = 0;

	while (s[idx])
	{
		if (ascii[(int)s[idx]] > 1)
		{
			write(1, (s + idx), 1);
			ascii[(int)s[idx]] = 0;
		}
		idx++;
	}
}

int		main(int argc, char *argv[])
{
	int 	ascii[255] = {0, };

	if (argc == 3)
	{
		check_ascii(argv[1], ascii);
		check_ascii(argv[2], ascii);
		print_parameter(argv[1], ascii);
	}
	write(1, "\n", 1);
	return (0);
}