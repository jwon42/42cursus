/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:47:09 by jwon              #+#    #+#             */
/*   Updated: 2020/09/16 19:35:04 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		update_value(t_env *env, t_list **envs)
{
	free(((t_env *)(*envs)->content)->value);
	((t_env *)(*envs)->content)->value = env->value;
	free(env->key);
	free(env);
}

static void		add_env_or_modify_value(char **argv, t_list **envs)
{
	t_env	*env;
	t_list	*curr;
	int		pos;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return ;
	pos = ft_strchr(*argv, '=') - *argv;
	env->key = ft_substr(*argv, 0, pos);
	env->value = ft_substr(*argv, pos + 1, ft_strlen(*argv) - pos - 1);
	curr = *envs;
	while (curr)
	{
		if (is_exist_key(env->key, curr))
		{
			update_value(env, &curr);
			return ;
		}
		curr = curr->next;
	}
	if (curr == NULL)
		ft_lstadd_back(envs, ft_lstnew(env));
}

void			cmd_export(char **argv, t_list *envs)
{
	char	**temp;

	if (argv[1] == NULL)
	{
		temp = convert_lst_to_arr(envs);
		sort_double_arr(temp);
		modify_env_for_export(temp);
		print_double_arr(temp);
		free_double_arr(temp);
		return ;
	}
	argv++;
	while (*argv)
	{
		if (!is_valid_for_export(*argv))
		{
			ft_putstr_fd("export: `", 1);
			ft_putstr_fd(*argv, 1);
			ft_putendl_fd("': not a valid identifier", 1);
			return ;
		}
		add_env_or_modify_value(argv, &envs);
		argv++;
	}
}
