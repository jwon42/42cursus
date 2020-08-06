/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:42:20 by jwon              #+#    #+#             */
/*   Updated: 2020/06/03 20:35:40 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int				idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int		idx;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		buf[idx] = str[idx];
		idx++;
	}
	buf[idx] = '\0';
	return (buf);
}


char	*ft_substr(char *str, int start, int len)
{
	int				idx;
	char			*buf;

	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		buf[idx] = str[start + idx];
		idx++;
	}
	buf[idx] = '\0';
	return (buf);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int				idx;
	char			*buf;

	if (!(buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	idx = 0;
	while (*s1)
		buf[idx++] = *s1++;
	while (*s2)
		buf[idx++] = *s2++;
	buf[idx] = '\0';
	return (buf);
}

int		get_next_line(char **line)
{
	int				len; // 개행까지의 길이 저장할 변수
	int				bytes; // read 함수 리턴 값 저장할 변수
	char			*tmp; // 정확한 free를 위해 사용할 임시 공간
	char			buf[2]; // read 할 공간, 0으로 초기화
	static char		*store; // read 한 내용 저장할 공간

	store = (store == NULL) ? ft_strdup("") : store;
	bytes = 1; // bytes 값 초기화
	while (bytes > 0 && !ft_strchr(store, '\n')) // eof 아니고, store에 개행이 없으면
	{
		bytes = read(0, buf, 1); // buf에 1byte씩 read
		buf[bytes] = '\0';
		tmp = ft_strjoin(store, buf); // store에 buf 이어붙이기
		free(store);
		store = tmp;
	}
	if (ft_strchr(store, '\n')) // store에 개행이 있으면
	{
		len = ft_strchr(store, '\n') - store; // 개행까지의 길이 측정 후 len에 저장
		*line = ft_substr(store, 0, len); // line에 store의 개행이전까지 저장
		tmp = ft_substr(store, len + 1, ft_strlen(store) - len); // store의 개행 이후부터를 다시 store에 저장
		free(store);
		store = tmp;
	}
	if (bytes == 0) // eof 이면
	{
		*line = ft_strdup(store); // line에 store 복사
		free(store);
		store = NULL;
	}
	return (bytes); // read 함수 반환값을 gnl 반환값으로 사용
}
