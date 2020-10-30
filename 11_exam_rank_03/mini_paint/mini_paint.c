/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:31:29 by jwon              #+#    #+#             */
/*   Updated: 2020/10/30 17:27:10 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ERR1 "Error: argument\n"
#define ERR2 "Error: Operation file corrupted\n"

int ft_strlen(char *str)
{
	int	idx;
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_perror(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	check_pos(float x, float y, float id_x, float id_y, float radius)
{
	float distance = sqrtf(powf(x - id_x, 2.) + powf(y - id_y, 2.));
	if (distance <= radius)
	{
		if ((radius - distance) < 1.00000000)
			return (0);
		return (1);
	}
	return (2);
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	char	*paper;
	int		read;
	int		pos;

	int		x;
	int		y;

	int		b_width;
	int		b_height;
	char	background;

	char	id;
	float	id_x;
	float	id_y;
	float	radius;
	char	color;

	if (argc != 2)
		return (ft_perror(ERR1));
	if (!(file = fopen(argv[1], "r")) ||
		(fscanf(file, "%d %d %c\n", &b_width, &b_height, &background) != 3) ||
		(!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300)))
		return (ft_perror(ERR2));
	paper = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(paper, background, b_width * b_height);
	while ((read = fscanf(file, "%c %f %f %f %c\n", &id, &id_x, &id_y, &radius, &color)) == 5)
	{
		if (!(radius > 0) || !(id == 'C' || id == 'c'))
			break ;
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				pos = check_pos((float)x, (float)y, id_x, id_y, radius);
				if (pos == 0 || (pos == 1 && id == 'C'))
					paper[y * b_width + x] = color;
				x++;
			}
			y++;
		}
	}
	if (read != -1)
	{
		free(paper);
		return (ft_perror(ERR2));
	}
	y = 0;
	while (y < b_height)
	{
		write(1, paper + y * b_width, b_width);
		write(1, "\n", 1);
		y++;
	}
	free(paper);
	fclose(file);
	return (0);
}
