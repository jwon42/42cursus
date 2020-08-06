/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:44:33 by jwon              #+#    #+#             */
/*   Updated: 2020/05/26 18:11:17 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_buffer(int fd, char **store)
{
	int				bytes;
	char			*tmp;
	char			*buf;

	buf = (BUFFER_SIZE > 0) ? malloc(sizeof(char) * (BUFFER_SIZE + 1)) : NULL;
	if ((bytes = read(fd, buf, BUFFER_SIZE)) < 0 || buf == NULL)
		return (-1);
	buf[bytes] = '\0';
	tmp = ft_strjoin(*store, buf);
	free(*store);
	*store = tmp;
	free(buf);
	buf = NULL;
	return ((bytes > 1) ? 1 : bytes);
}

void	split_store(char **store, char **line)
{
	size_t			len;
	char			*tmp;

	len = ft_strchr(*store, '\n') - *store;
	*line = ft_substr(*store, 0, len);
	tmp = ft_substr(*store, len + 1, ft_strlen(*store) - len);
	free(*store);
	*store = tmp;
}

int		get_next_line(int fd, char **line)
{
	int				bytes;
	static char		*store[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	store[fd] = (store[fd] == NULL) ? ft_strdup("") : store[fd];
	bytes = 1;
	while (bytes > 0 && !ft_strchr(store[fd], '\n'))
		bytes = read_buffer(fd, &store[fd]);
	if (ft_strchr(store[fd], '\n'))
		split_store(&store[fd], line);
	if (bytes == 0 && !ft_strchr(store[fd], '\n'))
	{
		*line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = NULL;
	}
	return ((bytes > 1) ? 1 : bytes);
}
