/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufs_crt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:16:22 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/26 13:35:58 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_buf_crt(t_info *info)
{
	int	i;
	int	j;

	info->buf = (int **)malloc(sizeof(int *) * info->height);
	if (!(info->buf))
		exit(0);
	i = 0;
	while (i < info->height)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * info->width);
		if (!(info->buf[i]))
			exit(0);
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}	
}

void	ft_texture_crt(t_info *info)
{
	int	i;
	int	j;

	info->texture = (int **)malloc(sizeof(int *) * 5);
	if (!(info->texture))
		exit(0);
	i = 0;
	while (i < 5)
	{
		info->texture[i] = (int *)malloc(sizeof(int)
				*(info->sqw_height * info->sqw_width));
		if (!(info->texture[i]))
			exit(0);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < info->sqw_height * info->sqw_width)
			info->texture[i][j++] = 1;
		i++;
	}	
}

void	ft_zbuffer_crt(t_info *info)
{
	int	i;

	info->zBuffer = (double *)malloc(sizeof(double) * (info->width));
	if (!(info->zBuffer))
		ft_exit();
	i = 0;
	while (i < info->width)
	{
		info->zBuffer[i] = 0;
		i++;
	}	
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image
		(info->mlx, path, &img->img_width, &img->img_height);
	if (!img->img)
		ft_exit();
	img->data = (int *)mlx_get_data_addr
		(img->img, &img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}	
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->so_path, &img);
	load_image(info, info->texture[1], info->no_path, &img);
	load_image(info, info->texture[2], info->we_path, &img);
	load_image(info, info->texture[3], info->ea_path, &img);
	load_image(info, info->texture[4], info->s_path, &img);
}
