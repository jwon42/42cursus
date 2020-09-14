/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:57:17 by jwon              #+#    #+#             */
/*   Updated: 2020/09/13 19:03:00 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_lst_to_arr(t_list *lst)
{
	int		idx;
	int		count;
	char	**arr;
	char	*keytmp;
	char	*valuetmp;

	count = ft_lstsize(lst);
	if (!(arr = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	idx = 0;
	while (lst)
	{
		keytmp = ft_strjoin(((t_env *)lst->content)->key, "=\"");
		valuetmp = ft_strjoin((((t_env *)lst->content)->value), "\"");
		arr[idx] = ft_strjoin(keytmp, valuetmp);
		free(keytmp);
		free(valuetmp);
		lst = lst->next;
		idx++;
	}
	arr[idx] = NULL;
	return (arr);
}

void	sort_double_arr(char **arr)
{
	int		i;
	char	*temp;

	i = 0;
	while (arr[i + 1])
	{
		if (ft_strncmp(arr[i], arr[i + 1], 100) > 0)
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

void	modify_env_for_export(char **arr)
{
	int		idx;
	char	*temp;

	idx = 0;
	while (arr[idx])
	{
		temp = ft_strjoin("declare -x ", arr[idx]);
		free(arr[idx]);
		arr[idx] = temp;
		idx++;
	}
}

void	print_double_arr(char **arr)
{
	int		idx;

	idx = 0;
	while (arr[idx])
		ft_putendl_fd(arr[idx++], 1);
}
