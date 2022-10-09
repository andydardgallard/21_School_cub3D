/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:22 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:04:56 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parcstruct_init(t_info *info)
{
	info->width = -1;
	info->height = -1;
	info->position = 0;
	info->floor_r = -1;
	info->floor_g = -1;
	info->floor_b = -1;
	info->ceilling_r = -1;
	info->ceilling_g = -1;
	info->ceilling_b = -1;
	info->no_path[0] = '\0';
	info->we_path[0] = '\0';
	info->ea_path[0] = '\0';
	info->so_path[0] = '\0';
	info->s_path[0] = '\0';
	info->count_lines = 0;
	info->error = 0;
	info->map_flag = 0;
	info->map_flag_spcs = 0;
	info->screenshot = 0;
	info->num_sprites = 0;
	info->max_clmns = 0;
}

void	ft_gamestruct_init(t_info *info)
{
	info->dir_x = -1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.66;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_ra = 0;
	info->key_la = 0;
	info->key_esc = 0;
	info->movespeed = 0.050001;
	info->rotSpeed = 0.05;
	info->sqw_height = 64;
	info->sqw_width = 64;
	info->pos_x = 0;
	info->pos_y = 0;
}

void	ft_check_file_name(char *str)
{
	int		i;
	char	*check;

	i = 0;
	check = str;
	if (ft_strlen(str) <= 4)
		ft_exit();
	while (*check != '\0')
	{
		if (*check++ == '.')
			i++;
	}
	if (i != 1)
		ft_exit();
	else
	{
		check = ft_strchr(str, '.');
		if (ft_strlen(check) != 4 || ft_strncmp(check, ".cub", 4) != 0)
		{
			printf("flag_error\n");
			exit (0);
		}			
	}	
}

void	ft_main_handler(t_info *info, int fd)
{	
	ft_parc(fd, info);
	close(fd);
	check_start_plr_position(info);
	ft_check_prmtr(info);
	info->mlx = mlx_init();
	init(info);
	if (info->screenshot == 0)
		mlx_loop(info->mlx);
	else
		ft_doscreenshot(info);
}

int	main (int argc, char *argv[])
{
	int		fd;
	t_info	info;

	if (argc < 2 || argc > 3)
		ft_exit();
	ft_parcstruct_init(&info);
	ft_gamestruct_init(&info);
	ft_check_file_name(argv[1]);
	if (info.error)
		ft_exit();
	if (argc == 3)
	{		
		if (ft_strlen(argv[2]) != 6 || ft_strncmp(argv[2], "--save", 6) != 0)
			ft_exit();
		else
			info.screenshot = 1;
	}
	fd = open(argv[1], O_RDONLY);
	ft_main_handler(&info, fd);
	exit(0);
	return (0);
}
