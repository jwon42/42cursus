/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:41:41 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/14 15:21:25 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_quote(t_quote *q)
{
	q->type = INIT;
	q->start = INIT;
	q->end = INIT;
}

static void		check_end(char *argv, int idx, t_quote *q)
{
	if ((argv[idx] == '\'' && q->type == QUOTE) ||
	(argv[idx] == '\"' && q->type == DQUOTE))
		q->end = idx - 1;
	else if ((argv[idx + 1] == '\0' && q->type == QUOTE) ||
	(argv[idx + 1] == '\0' && q->type == DQUOTE))
		q->end = idx;
	else if (q->type == ETC &&
	(argv[idx + 1] == '\'' || argv[idx + 1] == '\"' || argv[idx + 1] == '\0'))
		q->end = idx;
	return ;
}

static void		check_quote(char *argv, int idx, t_quote *q)
{
	if (q->type == INIT)
	{
		if (argv[idx] == '\'')
		{
			q->type = QUOTE;
			q->start = idx + 1;
		}
		else if (argv[idx] == '\"')
		{
			q->type = DQUOTE;
			q->start = idx + 1;
		}
		else
		{
			q->type = ETC;
			q->start = idx;
		}
		return ;
	}
	check_end(argv, idx, q);
}

char			*parse_env(char *argv, t_list *envs)
{
	int		idx;
	int		start;
	char	*temp[4];

	idx = -1;
	start = 0;
	while (argv[++idx])
	{
		if (argv[idx] == '$' || argv[idx + 1] == '\0')
		{
			if (start == 0)
			{
				temp[3] = ft_substr(argv, start, idx);
				start = idx + 1;
				continue ;
			}
			temp[0] = ft_substr(argv, start, idx - start + 1);
			temp[1] = ft_strdup(find_value(temp[0], envs));
			temp[2] = ft_strjoin(temp[3], temp[1]);
			free(temp[3]);
			temp[3] = temp[2];
			start = idx + 1;
		}
	}
	return (temp[3]);
}

char			*parse_quote(char *argv, t_list *envs)
{
	int		idx;
	char	*tmp[4];
	t_quote	q;

	idx = -1;
	tmp[0] = "";
	init_quote(&q);
	while (argv[++idx])
	{
		check_quote(argv, idx, &q);
		if (q.end != INIT)
		{
			tmp[1] = ft_substr(argv, q.start, q.end - q.start + 1);
			if (q.type == DQUOTE && has_env(tmp[1]))
				tmp[1] = parse_env(tmp[1], envs);
			tmp[2] = ft_strjoin(tmp[0], tmp[1]);
			if (tmp[0] && *tmp[0])
				free(tmp[0]);
			if (tmp[1])
				free(tmp[1]);
			tmp[0] = tmp[2];
			init_quote(&q);
		}
	}
	return (tmp[0]);
}
