/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:34:11 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/26 17:26:31 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_flr_clng_cast(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = info->height / 2 + 1;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			color = info->floor_b;
			color = color | info->floor_g << 8;
			color = color | info->floor_r << 16;
			info->buf[y][x] = color;
			color = info->ceilling_b;
			color = color | info->ceilling_g << 8;
			color = color | info->ceilling_r << 16;
			info->buf[info->height - y - 1][x] = color;
			++x;
		}		
		++y;
	}	
}

int	ft_texture_side(t_cast *cast, t_info *info)
{
	int	color;

	if (cast->side == 0)
	{
		if (cast->ray_dir_x < 0)
			color = info->texture[1][info->sqw_height
				* cast->tex_y + cast->tex_x];
		else
			color = info->texture[0][info->sqw_height
				* cast->tex_y + cast->tex_x];
	}
	else
	{
		if (cast->ray_dir_y < 0)
			color = info->texture[3][info->sqw_height
				* cast->tex_y + cast->tex_x];
		else
			color = info->texture[2][info->sqw_height
				* cast->tex_y + cast->tex_x];
	}
	return (color);
}

void	ft_draw_wals_calc(t_cast *cast, t_info *info, int x)
{
	int	y;
	int	color;

	y = cast->draw_start;
	while (y < cast->draw_end)
	{		
		cast->tex_y = (int)cast->tex_pos & (info->sqw_height - 1);
		cast->tex_pos += cast->step;
		color = ft_texture_side(cast, info);
		if (cast->side == 0)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}

void	ft_draw_walls(t_cast *cast, t_info *info, int x)
{
	int		line_height;	
	double	wall_x;

	line_height = (int)(info->height / cast->perp_wall_dist);
	cast->draw_start = -line_height / 2 + info->height / 2;
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = line_height / 2 + info->height / 2;
	if (cast->draw_end >= info->height)
		cast->draw_end = info->height - 1;
	if (cast->side == 0)
		wall_x = info->pos_y + cast->perp_wall_dist * cast->ray_dir_y;
	else
		wall_x = info->pos_x + cast->perp_wall_dist * cast->ray_dir_x;
	wall_x -= floor((wall_x));
	cast->tex_x = (int)(wall_x * (double)info->sqw_width);
	ft_raydir_drw_handle(info, cast);
	cast->step = 1.0 * info->sqw_width / line_height;
	cast->tex_pos = (cast->draw_start - info->height / 2
			+ line_height / 2) * cast->step;
	ft_draw_wals_calc(cast, info, x);
}

void	ft_wall_cast(t_info *info)
{
	int		x;
	t_cast	cast;

	x = 0;
	while (x < info->width)
	{
		cast.hit = 0;
		cast.camera_x = 2 * x / (double)info->width - 1;
		cast.ray_dir_x = info->dir_x + info->plane_x * cast.camera_x;
		cast.ray_dir_y = info->dir_y + info->plane_y * cast.camera_x;
		cast.map_x = (int)info->pos_x;
		cast.map_y = (int)info->pos_y;
		cast.delta_dist_x = fabs(1 / cast.ray_dir_x);
		cast.delta_dist_y = fabs(1 / cast.ray_dir_y);
		ft_raydir_handle(info, &cast);
		ft_dda(info, &cast);
		if (cast.side == 0)
			cast.perp_wall_dist = (cast.map_x - info->pos_x
					+ (1 - cast.step_x) / 2) / cast.ray_dir_x;
		else
			cast.perp_wall_dist = (cast.map_y - info->pos_y
					+ (1 - cast.step_y) / 2) / cast.ray_dir_y;
		ft_draw_walls(&cast, info, x);
		info->zBuffer[x++] = cast.perp_wall_dist;
	}
}
