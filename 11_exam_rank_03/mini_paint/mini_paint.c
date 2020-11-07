/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:31:29 by jwon              #+#    #+#             */
/*   Updated: 2020/11/07 19:01:54 by jwon             ###   ########.fr       */
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
	int	idx = 0;
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
	int		read, pos;
	int		x, y;

	int		b_width, b_height;
	char	background;

	char	id, color;
	float	id_x, id_y, radius;

	if (argc != 2) // 인자가 없으면
		return (ft_perror(ERR1)); // 1번 에러 출력, 함수종료
	if (!(file = fopen(argv[1], "r")) || // 첫번째 인자의 파일을 오픈할 수 없거나
		(fscanf(file, "%d %d %c\n", &b_width, &b_height, &background) != 3) || // 파일의 첫번째 줄이 조건에 부합하지 않거나
		(!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300)) || // 배경이 정해진 범위가 아니거나
		(!(paper = (char *)malloc(sizeof(char) * (b_width * b_height))))) // 배경만큼을 메모리 할당할 수 없다면
		return (ft_perror(ERR2)); // 2번 에러 출력, 함수종료
	memset(paper, background, b_width * b_height); // 배경 그리기
	while ((read = fscanf(file, "%c %f %f %f %c\n", &id, &id_x, &id_y, &radius, &color)) == 5) // 파일의 두번째 줄부터 조건(형식, 갯수)에 부합하면 반복
	{
		if (!(radius > 0) || !(id == 'C' || id == 'c')) // radius 값이 음수거나, id가 'C'또는 'c'가 아니면
			break ; // 반복문 탈출
		y = -1;
		while (++y < b_height) // 배경 높이까지 반복
		{
			x = -1;
			while (++x < b_width) // 배경 너비까지 반복
			{
				pos = check_pos((float)x, (float)y, id_x, id_y, radius); // 경계 체크
				if (pos == 0 || (pos == 1 && id == 'C'))
					paper[y * b_width + x] = color; // 그리기
			}
		}
	}
	if (read != -1) // 반복문 탈출했는데 그 이유가 읽기 실패한게 아니라면? 조건에 부합하지 않는 것이기에
	{
		free(paper); // 배경 메모리 해제
		return (ft_perror(ERR2)); // 2번 에러 출력, 함수종료
	}
	y = -1;
	while (++y < b_height) // 배경 높이까지 반복
	{
		write(1, paper + y * b_width, b_width); // 그림 그리기
		write(1, "\n", 1); // 개행
	}
	free(paper); // 배경 메모리 해제
	fclose(file); // 파일 닫기
	return (0); // 함수 종료
}
