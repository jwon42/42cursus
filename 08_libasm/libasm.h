/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:11:53 by jwon              #+#    #+#             */
/*   Updated: 2020/09/01 17:14:37 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define	RED "\x1b[31m"
# define	YELLOW "\x1b[33m"
# define	RESET "\x1b[0m"

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(const char *dst, const char *src);
char		*ft_strdup(const char *s1);
ssize_t		ft_read(int fd, void *buff, size_t nbyte);
ssize_t		ft_write(int fd, void *buff, size_t nbyte);

#endif