/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:12:18 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 18:06:32 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

/*
** resolution id list
*/
# define X 0
# define Y 1

/*
** texture id list
*/
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4
# define TEX_END 5

/*
** color id list
*/
# define COLOR_F 0
# define COLOR_C 1
# define COLOR_END 2

/*
** all id list
*/
# define ID_R 0
# define ID_NO 1
# define ID_SO 2
# define ID_WE 3
# define ID_EA 4
# define ID_S 5
# define ID_F 6
# define ID_C 7
# define ID_MAP 8
# define ID_END 9

# define SAVE 0
# define DEBUG 1

/*
** mlx key
*/
# define MLX_KEY_PRESS 2
# define MLX_KEY_RELEASE 3
# define MLX_MOUSE 4
# define MLX_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_R	15
# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2
# define KEY_F 	3
# define KEY_Q	12
# define KEY_E	14
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_TAB 48
# define KEY_MINUS 27
# define KEY_PLUS 24
# define PLAYER_SIZE 3

/*
** coordinate(double) struct
*/
typedef struct			s_coord_d
{
	double				x;
	double				y;
}						t_coord_d;

/*
** cordinate(int) struct
*/
typedef struct			s_coord_i
{
	int					x;
	int					y;
}						t_coord_i;

/*
** mlx_img struct
*/
typedef struct			s_img
{
	void				*img;
	char				*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

/*
** ray struct
*/
typedef struct			s_ray
{
	int					pix;
	double				camera_x;
	t_coord_i			map;
	t_coord_i			step;
	t_coord_d			ray_dir;
	t_coord_d			side_dist;
	t_coord_d			delta_dist;
	double				perp_wall_dist;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				*z_buffer;
}						t_ray;

/*
** sprite struct
*/
typedef struct			s_sprite
{
	t_coord_i			coord;
}						t_sprite;

typedef struct			s_sprites
{
	t_coord_i			coord;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_coin
{
	t_coord_i			coord;
}						t_coin;

typedef struct			s_coins
{
	t_coord_i			coord;
	struct s_coins		*next;
}						t_coins;

typedef struct			s_fence
{
	t_coord_i			coord;
}						t_fence;

typedef struct			s_fences
{
	t_coord_i			coord;
	struct s_fences		*next;
}						t_fences;

typedef struct			s_yeji
{
	t_coord_i			coord;
}						t_yeji;

typedef struct			s_yejis
{
	t_coord_i			coord;
	struct s_yejis		*next;
}						t_yejis;

typedef struct			s_draw_sprite
{
	t_sprite			*sprites;
	int					i;
	t_coord_d			sprite;
	double				inv_det;
	t_coord_d			transform;
	t_coord_i			draw_start;
	t_coord_i			draw_end;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					stripe;
	int					y;
	int					d;
	t_coord_i			tex;
	int					color;
	int					totcolor;
}						t_draw_sprite;

typedef struct			s_draw_coin
{
	t_coin				*coins;
	int					i;
	t_coord_d			coin;
	double				inv_det;
	t_coord_d			transform;
	t_coord_i			draw_start;
	t_coord_i			draw_end;
	int					coin_screen_x;
	int					coin_height;
	int					coin_width;
	int					stripe;
	int					y;
	int					d;
	t_coord_i			tex;
	int					color;
	int					totcolor;
}						t_draw_coin;

typedef struct			s_draw_fence
{
	t_fence				*fences;
	int					i;
	t_coord_d			fence;
	double				inv_det;
	t_coord_d			transform;
	t_coord_i			draw_start;
	t_coord_i			draw_end;
	int					fence_screen_x;
	int					fence_height;
	int					fence_width;
	int					stripe;
	int					y;
	int					d;
	t_coord_i			tex;
	int					color;
	int					totcolor;
}						t_draw_fence;

typedef struct			s_draw_yeji
{
	t_yeji				*yejis;
	int					i;
	t_coord_d			yeji;
	double				inv_det;
	t_coord_d			transform;
	t_coord_i			draw_start;
	t_coord_i			draw_end;
	int					yeji_screen_x;
	int					yeji_height;
	int					yeji_width;
	int					stripe;
	int					y;
	int					d;
	t_coord_i			tex;
	int					color;
	int					totcolor;
}						t_draw_yeji;

typedef struct			s_key
{
	int					go;
	int					back;
	int					left;
	int					right;
	int					go_left;
	int					go_right;
	int					turn;
	int					cam_up;
	int					cam_down;
	int					rotate_left;
	int					rotate_right;
	int					speed_down;
	int					speed_up;
	int					slow;
	int					mouse_move;
	int					mouse_stop;
}						t_key;

/*
** player infomation struct
*/
typedef struct			s_player
{
	int					id;
	int					cnt;
	double				cam_height;
	t_coord_d			pos;
	t_coord_d			dir;
	t_coord_d			plane;
}						t_player;

/*
** map config struct
*/
typedef struct			s_config
{
	int					id[ID_END];
	int					res[2];
	char				*texture[TEX_END];
	int					color[COLOR_END];
	char				**map;
	char				*map_name;
	int					row;
	int					col;
	int					coin;
	int					flag[2];
	int					fence_cnt;
	t_coord_i			fence;
	int					warp_cnt;
	t_coord_d			warp[10];
	t_player			player;
}						t_config;

typedef struct			s_game
{
	void				*mlx;
	void				*win;
	double				speed_mov;
	double				speed_rot;
	int					debug;
	int					health;
	int					openfence;
	t_key				*key;
	t_img				*img;
	t_img				skybox;
	t_img				**tex;
	t_img				*sprite;
	t_sprites			*sprites;
	t_img				*coin;
	t_coins				*coins;
	t_img				*fence;
	t_fences			*fences;
	t_img				*yeji;
	t_yejis				*yejis;
	t_config			config;
}						t_game;

/*
** utils
*/
void					exit_program(char *str, int status);
void					view_debug(t_game *game);
void					view_skybox(t_game *game);
void					view_iteminfo(t_game *game);
void					view_lifebar(t_game *game);

/*
** parse
*/
void					parse_hub(int argc, char *argv[], t_game *game);
void					parse_resolution(char *line, t_config *config);
void					parse_texture(char *line, int id, t_config *config);
int						check_texture_id(char *line, t_config *config);
void					parse_color(char *line, int id, t_config *config);
int						check_color_id(char *line, t_config *config);
void					parse_map(int ret, char *line, t_config *config);
void					save_player_info(int row, int col, t_config *config);

/*
** parse utils
*/
int						check_filename_ext(char *filename, char *ext);
void					check_identifiers_exist(int ret, t_config *config);
int						check_valid_chr(char c);

/*
** init
*/
void					init_hub(t_game *game);
void					init_game_coin(t_game *game);
void					init_game_fence(t_game *game);
void					convert_xpm_to_img(t_game *game);
void					init_game_textures(t_game *game, int cnt);
void					init_game_sprite(t_game *game);
void					init_game_coin(t_game *game);
void					init_game_fence(t_game *game);
void					init_game_yeji(t_game *game);
void					set_coin(char *path, t_game *game);
void					set_fence(char *path, t_game *game);
void					set_yeji(char *path, t_game *game);

/*
** config key & window
*/
int						key_manager(t_game *game);
void					key_released(int key, void *parameter);
void					key_pressed(int key, void *parameter);
void					exit_window(void *parameter);

/*
** control camera & player
*/
void					move_go(t_game *game);
void					move_back(t_game *game);
void					move_left(t_game *game);
void					move_right(t_game *game);
void					turn_around(t_game *game);
void					camera_up(t_game *game);
void					camera_down(t_game *game);
void					rotate_left(t_game *game);
void					rotate_right(t_game *game);
void					game_speed_up(t_game *game);
void					game_speed_down(t_game *game);

/*
** raycasting & utils
*/
int						raycasting(t_game *game);
void					perp_and_height(t_ray *ray,
										t_player *player, t_game *game);
void					hit(t_ray *ray, t_game *game);
void					check_coin(t_game *game);
void					check_warp(t_game *game);
void					open_fence(t_game *game);
int						check_around_chr(t_game *game, char c);

/*
** sprite
*/
int						draw_sprite(t_ray *ray, t_game *game);
void					is_sprite(t_ray *ray, t_game *game);
void					sort_sprite(t_game *game,
									t_sprite *sprites, int nbr_sprites);
t_sprite				*list_to_tab_sprite(t_game *game);

/*
** coin
*/
int						draw_coin(t_ray *ray, t_game *game);
void					is_coin(t_ray *ray, t_game *game);
void					sort_coin(t_game *game,
									t_coin *coins, int nbr_coins);
t_coin					*list_to_tab_coin(t_game *game);

/*
** fence
*/
int						draw_fence(t_ray *ray, t_game *game);
void					is_fence(t_ray *ray, t_game *game);
void					sort_fence(t_game *game,
									t_fence *fences, int nbr_fences);
t_fence					*list_to_tab_fence(t_game *game);

/*
** yeji
*/
int						draw_yeji(t_ray *ray, t_game *game);
void					is_yeji(t_ray *ray, t_game *game);
void					sort_yeji(t_game *game, t_yeji *yejis, int nbr_yejis);
t_yeji					*list_to_tab_yeji(t_game *game);

/*
** texture
*/
void					texturisation(t_ray *ray, t_game *game);

/*
** image
*/
void					pixel_put_to_image(int color, int x, int y, t_img *img);
void					ver_line_color_image(t_line *line,
											t_game *game, int color);
void					ver_line_texture_image(t_line *line, t_game *game,
												t_img *tex, t_ray *ray);
t_img					*new_image(t_game *game, int x_len, int y_len);

/*
** srceenshot
*/
void					create_screenshot(t_img *mlx_img, char *name);

/*
** play sound
*/
void					play_bgm(void);
void					play_sound_effect(int type);

#endif
