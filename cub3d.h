/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:50:13 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:18:35 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_ra;
	int		key_la;
	int		key_esc;	
	t_img	img;
	int		**buf;	
	int		**texture;
	double	movespeed;
	double	rotSpeed;
	char	**array_map;
	char	**arr_fullfil;
	int		floor_r;
	int		floor_g;
	int		floor_b;	
	int		ceilling_r;
	int		ceilling_g;
	int		ceilling_b;
	char	no_path[100];
	char	we_path[100];
	char	ea_path[100];
	char	so_path[100];
	char	s_path[100];	
	char	*position;
	int		count_lines;
	int		max_clmns;
	int		width;
	int		height;
	int		sqw_height;
	int		sqw_width;	
	double	*zBuffer;
	double	**sprite;
	int		num_sprites;	
	char	start_pos;
	int		*max_size_x;
	int		*max_size_y;
	int		error;
	int		map_flag;
	int		map_flag_spcs;
	int		screenshot;
	int		*maxs;	
	int		*sprite_order;
	double	*sprite_distance;
}			t_info;

typedef struct s_cast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		tex_x;
	int		tex_y;
	int		draw_start;
	int		draw_end;
	double	step;
	double	tex_pos;
}			t_cast;

typedef struct s_sprt_drw
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		tex_y;
}			t_sprt_drw;

typedef struct s_pair
{
	double	first;
	int		second;
}			t_pair;	

char	*ft_strjoin_free(char *str1, char *str2);
int		ft_fullfil_start(t_info *map_parcer);
int		ft_check_prmtr(t_info *info);
void	ft_parc(int fd, t_info *info);
void	check_start_plr_position(t_info *info);
int		ft_gnl(char **line, int fd, t_info *info);
int		ft_atoi_resltn(char *str, t_info *info);
int		ft_atoi_flr(char *str, t_info *info);
int		ft_strlen_path(char *str);
int		ft_check_smbls(char c);
int		ft_check_smbls_tail(char c);
int		ft_check_map_smbls(char *str);
int		ft_check_tail(char *end);
void	ft_check_plr_smbls(char *common, t_info *info);
int		ft_crt_arr_flfl(t_info *info);
void	ft_exit(void);
int		ft_write_resltn(char *line, t_info *info);
int		ft_write_flr(char *line, t_info *info);
int		ft_flr_cnt(char *line);
void	ft_strncpy_path(char *src, int size, char path[], t_info *info);
int		ft_cnt_max_width(int *maxs, char *common, t_info *info);
int		ft_mas_check(t_info *info, int c);
int		ft_write_clng(char *line, t_info *info);
void	ft_flr_check_bfr_nmbr(char *line, t_info *info);
void	ft_flr_check_cmm(t_info *info);
void	ft_chcks_plr_pstn(t_info *info, int i, int j);
void	ft_fill_n_pstn(t_info *info);
void	ft_fill_e_pstn(t_info *info);
void	ft_fill_w_pstn(t_info *info);
void	ft_fill_s_pstn(t_info *info);
int		ft_cnt_max_i(int max, int maxs);
void	ft_parc_map(t_info *info, char *spec, char **common, char *sln);
int		ft_check_desc_ones(t_info *info);
void	ft_parc_r(char *spec, char *line, t_info *info);
void	ft_parc_f(char *spec, char *line, t_info *info);
void	ft_parc_c(char *spec, char *line, t_info *info);
void	ft_parc_n(char *line, t_info *info);
void	ft_parc_w (char *line, t_info *info);
char	*ft_parc_utils_one(char *spec, char *line, t_info *info, char c);
char	*ft_parc_utils_two(char *spec, char *end, t_info *info, char *path);
char	*ft_parc_utils_three(char *spec, char *slh, t_info *info, char *path);
void	ft_parc_e (char *line, t_info *info);
char	*ft_parc_utils_four(char *spec, char *line, t_info *info, char c);
void	ft_parc_s(char *spec, char *line, t_info *info);
void	ft_check_desc_aftr_prc(t_info *info);
void	ft_crt_common_buf(char **common, char **sln, t_info *info);
void	ft_fill_array(t_info *info, char *common, int max);
void	ft_fill_arr(char *common, int *c, int *i, char *chr);
char	*ft_fill_arr_cnt(char *for_cnt, int *cnt);
void	load_texture(t_info *info);
int		ft_mas_sprites(t_info *info);
void	ft_cnt_sprites(t_info *info);
void	ft_zbuffer_crt(t_info *info);
void	ft_buf_crt(t_info *info);
void	ft_texture_crt(t_info *info);
void	key_update(t_info *info);
void	draw(t_info *info);
void	calc(t_info *info);
void	init(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	key_d_update(t_info *info);
void	key_a_update(t_info *info);
void	key_s_update(t_info *info);
void	key_w_update(t_info *info);
void	ft_ra_update(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
int		close_wind(void);
void	ft_flr_clng_cast(t_info *info);
void	ft_wall_cast(t_info *info);
void	ft_raydir_handle(t_info *info, t_cast *cast);
void	ft_raydir_drw_handle(t_info *info, t_cast *cast);
void	ft_dda(t_info *info, t_cast *cast);
void	ft_sprites_calc(t_info *info);
void	sortSprites(int *order, double *dist, int amount);
void	ft_sprites_arr_crt(t_info *info);
void	ft_doscreenshot(t_info *info);
void	ft_print_arr(t_info *info);
void	ft_kstl(char *slh);
#endif