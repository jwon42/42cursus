NAME	=	minishell

SRCS	= 	srcs/main.c \
			srcs/cmd_env.c \
			srcs/cmd_exit.c \
			srcs/cmd_export.c \
			srcs/cmd_pwd_cd_echo.c \
			srcs/cmd_redir.c \
			srcs/cmd_unset.c \
			srcs/control_signal.c \
			srcs/exec_cmds.c \
			srcs/exec_pipe.c \
			srcs/exec_redir.c \
			srcs/get_argv.c \
			srcs/get_cmds.c \
			srcs/get_envs.c \
			srcs/parse_quote_env.c \
			srcs/show_prompt_art.c \
			srcs/utils_env.c \
			srcs/utils_export.c \
			srcs/utils_has.c \
			srcs/utils_redir.c \
			srcs/utils.c \

LEAKS	=	-g3 -fsanitize=address

LIBS	=	-L./libs/libft -lft

LIBFT	=	libft.a

HEADER	=	-I./includes

FLAG	= 	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(HEADER) $(FLAG) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libs/libft

clean	:
	$(MAKE) -C ./libs/libft clean
	rm -rf $(OBJS)

fclean	:
	$(MAKE) -C ./libs/libft fclean
	rm -rf $(NAME)

re		: fclean all
