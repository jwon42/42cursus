/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:01:51 by jwon              #+#    #+#             */
/*   Updated: 2020/09/14 12:10:09 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libs/libft/libft.h"

# define INIT	-1
# define QUOTE	39
# define DQUOTE	34
# define ETC	42
# define REDIR	62
# define DREDIR	6
# define BREDIR	60

int				g_exit_value;
char			**g_envp;
char			*g_env_user;

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

typedef struct	s_quote
{
	int			type;
	int			start;
	int			end;
}				t_quote;

typedef struct	s_redir
{
	int			argc;
	char		**argv;
	char		**cmds;
	char		*types;
}				t_redir;

typedef struct	s_pipe
{
	char		*line;
	char		**argv;
}				t_pipe;

/*
**	main.c
*/
void			setup(t_list *envs);

/*
**	control_signal.c
*/
void			handle_signal(int signo);

/*
**	show_prompt_art.c
*/
int				input_from_prompt(char **line);
void			show_prompt(char *user);
void			show_art(void);

/*
**	get_envs.c
*/
t_list			*get_envs(int argc, char **argv, char **envp);

/*
**	get_cmds.c
*/
char			**get_cmds(char *line);

/*
**	get_argv.c
*/
char			*modify_argv(char *str, t_list *envs);
char			**get_argv(char *line, t_list *envs);

/*
**	utils.c
*/
int				ft_puterror_fd(char *s1, char *s2, int fd);
char			*substr_and_trim(char *command, int start, \
				int num, char *charset);
void			free_double_arr(char **arr);

/*
**	utils_env.c
*/
int				is_valid_env(char *arg);
int				is_exist_key(char *key, t_list *envs);
char			*find_value(char *key, t_list *envs);
char			*find_path(char *argv, t_list *envs);

/*
**	utils_export.c
*/
char			**convert_lst_to_arr(t_list *lst);
void			sort_double_arr(char **arr);
void			modify_env_for_export(char **arr);
void			print_double_arr(char **arr);

/*
**	utils_has.c
*/
int				has_quote(char *str);
int				has_env(char *str);
int				has_pipe(char *str);
int				has_redir(char *str);

/*
**	utils_redir.c
*/
int				is_single_redir(char *command, int i);
int				find_redir_type(char *command, int i);
int				has_redir_syntax_error(char *str);

/*
**	parse_quote_env.c
*/
char			*parse_env(char *argv, t_list *envs);
char			*parse_quote(char *argv, t_list *envs);

/*
**	cmd_pwd_cd_echo.c
*/
void			cmd_pwd(void);
void			cmd_cd(char **argv, t_list *envs);
void			cmd_echo(char **argv);

/*
**	cmd_exit.c
*/
void			cmd_exit(char **argv);

/*
**	cmd_env.c
*/
void			cmd_env(char **argv, t_list *envs);

/*
**	cmd_export.c
*/
void			cmd_export(char **argv, t_list *envs);

/*
**	cmd_unset.c
*/
void			cmd_unset(char **argv, t_list *envs);

/*
**	exec_redir.c
*/
void			init_redir(char *command, t_redir *r);
int				parse_redir(char *command, t_redir *r);
void			open_unnecessary_files(t_redir *r);
void			exec_redir(char *line, t_list *envs);

/*
**	cmd_redir.c
*/
void			cmd_redir(t_redir *r, t_list *envs);

/*
**	exec_pipe.c
*/
void			parse_pipe(char **line, t_pipe *p, t_list *envs);
void			exec_pipe(char *line, t_list *envs);

/*
**	exec_cmds.c
*/
int				exec_builtin(char *line, t_list *envs);
void			exec_others(char *line, t_list *envs);
void			exec_cmds(char *line, t_list *envs);

#endif
