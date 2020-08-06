/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:43:14 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:29:10 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	data_to_bmp(t_img *mlx_img, int fd)
{
	int i;

	i = mlx_img->width * mlx_img->height - 1;
	while (i >= 0)
	{
		write(fd, &mlx_img->data[i * mlx_img->bpp / 8], 4);
		i--;
	}
	return (1);
}

static void	make_vertical_pixel(t_img *mlx_img, int line_cnt, int *e, int f)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = mlx_img->data[*e + (line_cnt * mlx_img->size_l)];
		mlx_img->data[*e + (line_cnt * mlx_img->size_l)] =
			mlx_img->data[f - k + (line_cnt * mlx_img->size_l - 1)];
		mlx_img->data[f - k + (line_cnt * mlx_img->size_l - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

static int	make_vertical_line(t_img *mlx_img)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < mlx_img->height)
	{
		e = 0;
		f = mlx_img->size_l;
		while (e < f && e != f)
		{
			make_vertical_pixel(mlx_img, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
	return (1);
}

static int	make_bmp_header(t_img *mlx_img, int fd)
{
	int header_size;
	int plane_nbr;
	int o_count;

	header_size = 40;
	plane_nbr = 1;
	write(fd, &header_size, 4);
	write(fd, &mlx_img->width, 4);
	write(fd, &mlx_img->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &mlx_img->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (1);
}

void		create_screenshot(t_img *mlx_img, char *filename)
{
	int fd;
	int file_size;
	int first_pix;

	filename = ft_strjoin(filename, ".bmp");
	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
		exit(EXIT_FAILURE);
	file_size = 14 + 40 + 4 + (mlx_img->width * mlx_img->height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	make_bmp_header(mlx_img, fd);
	make_vertical_line(mlx_img);
	data_to_bmp(mlx_img, fd);
	close(fd);
	free(filename);
	exit(EXIT_SUCCESS);
}
