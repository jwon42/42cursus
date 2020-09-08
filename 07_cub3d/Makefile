# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 20:41:23 by jwon              #+#    #+#              #
#    Updated: 2020/08/04 17:57:38 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

SRCS 		=	srcs/cub3d.c \
				srcs/view_debug.c \
				srcs/utils.c \
				srcs/parse_hub.c \
				srcs/parse_resolution.c \
				srcs/parse_texture_color.c \
				srcs/parse_map.c \
				srcs/parse_map_player.c \
				srcs/parse_utils.c \
				srcs/init_hub.c \
				srcs/init_xpm.c \
				srcs/control_camera.c \
				srcs/control_player.c \
				srcs/control_speed.c \
				srcs/config_key.c \
				srcs/raycasting_1.c \
				srcs/raycasting_2.c \
				srcs/sprite.c \
				srcs/draw_sprite.c \
				srcs/texture.c \
				srcs/image.c \
				srcs/screenshot.c \

BNS_SRCS	=	srcs/bonus/cub3d.c \
				srcs/bonus/view_debug_bonus.c \
				srcs/bonus/view_skybox_bonus.c \
				srcs/bonus/view_lifebar_bonus.c \
				srcs/bonus/utils_bonus.c \
				srcs/bonus/parse_hub_bonus.c \
				srcs/bonus/parse_resolution_bonus.c \
				srcs/bonus/parse_texture_color_bonus.c \
				srcs/bonus/parse_map_bonus.c \
				srcs/bonus/parse_map_player_bonus.c \
				srcs/bonus/parse_utils_bonus.c \
				srcs/bonus/init_hub_bonus.c \
				srcs/bonus/init_xpm_bonus.c \
				srcs/bonus/init_textures_bonus.c \
				srcs/bonus/init_bonus_sprites_bonus.c \
				srcs/bonus/control_camera_bonus.c \
				srcs/bonus/control_player_bonus.c \
				srcs/bonus/control_speed_bonus.c \
				srcs/bonus/config_key_bonus.c \
				srcs/bonus/raycasting_1_bonus.c \
				srcs/bonus/raycasting_2_bonus.c \
				srcs/bonus/raycasting_3_bonus.c \
				srcs/bonus/cal_sprite_bonus.c \
				srcs/bonus/draw_sprite_bonus.c \
				srcs/bonus/cal_coin_bonus.c \
				srcs/bonus/draw_coin_bonus.c \
				srcs/bonus/cal_fence_bonus.c \
				srcs/bonus/draw_fence_bonus.c \
				srcs/bonus/cal_yeji_bonus.c \
				srcs/bonus/draw_yeji_bonus.c \
				srcs/bonus/texture_bonus.c \
				srcs/bonus/image_bonus.c \
				srcs/bonus/screenshot_bonus.c \
				srcs/bonus/play_sound_bonus.c

OBJS		=	${SRCS:%.c=%.o}

BNS_OBJS	=	${BNS_SRCS:%.c=%.o}

FLAGS		=	-Wall -Wextra -Werror

LEAKS		=	-g3 -fsanitize=address -fsanitize=undefined -std=c99

MLX			=	-Llibs/minilibx -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS) $(BNS_OBJS)
	@printf '\n\033[33m[ Compile libft ]\033[0m\n'
	@$(MAKE) re -C ./libs/libft
	@$(MAKE) re -C ./libs/minilibx
	@printf '\n\033[33m[ Compile cub3D ]\033[0m';
	@for (( i = 1 ; i < 30 ; i++ )); do sleep 0.01; printf '%s' .; done
	@gcc $(FLAGS) $(OBJS) -I./includes $(MLX) ./libs/libft/libft.a -o $(NAME)
	@echo '100%'
	@printf '\n\033[32m[ SUCCESS ]\033[0m\n\n'

all : $(NAME)

clean :
	@printf '\n\033[33m[ Remove libft object files ]\033[0m\n'
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./libs/minilibx
	@printf '\n\033[33m[ Remove cub3D object files ]\033[0m\n'
	rm -rf $(OBJS) $(BNS_OBJS)

fclean : clean
	@printf '\n\033[33m[ Remove executive file ]\033[0m\n'
	rm -rf $(NAME)
	rm -rf screenshot.bmp
	@printf '\n'

bonus : fclean $(NAME)
	@gcc $(FLAGS) $(BNS_OBJS) -I./includes $(MLX) ./libs/libft/libft.a -o $(NAME)

re : fclean	all
