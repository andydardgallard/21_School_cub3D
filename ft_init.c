/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:41 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 15:46:34 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprites_arr_crt(t_info *info)
{
	info->sprite_order = (int *)malloc(sizeof(int) * info->num_sprites);
	if (!(info->sprite_order))
		ft_exit();
	info->sprite_distance = (double *)malloc(sizeof(double)
			* info->num_sprites);
	if (!(info->sprite_distance))
		ft_exit();
}

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[y * info->width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	if (info->screenshot == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{	
	ft_flr_clng_cast(info);
	ft_wall_cast(info);
	ft_sprites_calc(info);
}

int	main_loop(t_info *info)
{	
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

void	init(t_info *info)
{	
	if (info->screenshot == 0)
		info->win = mlx_new_window(info->mlx, info->width,
				info->height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
			&info->img.bpp, &info->img.size_l, &info->img.endian);
	ft_buf_crt(info);
	ft_texture_crt(info);
	ft_zbuffer_crt(info);
	ft_cnt_sprites(info);
	ft_mas_sprites(info);
	load_texture(info);
	ft_sprites_arr_crt(info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	if (info->screenshot == 0)
	{		
		mlx_hook(info->win, 2, (1L << 0), &key_press, info);
		mlx_hook(info->win, 3, (1L << 0), &key_release, info);
		mlx_hook(info->win, 17, (1L << 0), &close_wind, info);
	}
}
