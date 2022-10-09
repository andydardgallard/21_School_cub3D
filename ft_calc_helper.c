/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:07:49 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/26 17:31:45 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raydir_handle(t_info *info, t_cast *cast)
{
	if (cast->ray_dir_x < 0)
	{
		cast->step_x = -1;
		cast->side_dist_x = (info->pos_x - cast->map_x)
			* cast->delta_dist_x;
	}
	else
	{
		cast->step_x = 1;
		cast->side_dist_x = (cast->map_x + 1.0 - info->pos_x)
			* cast->delta_dist_x;
	}
	if (cast->ray_dir_y < 0)
	{
		cast->step_y = -1;
		cast->side_dist_y = (info->pos_y - cast->map_y)
			* cast->delta_dist_y;
	}
	else
	{
		cast->step_y = 1;
		cast->side_dist_y = (cast->map_y + 1.0 - info->pos_y)
			* cast->delta_dist_y;
	}
}

void	ft_dda(t_info *info, t_cast *cast)
{
	while (cast->hit == 0)
	{		
		if (cast->side_dist_x < cast->side_dist_y)
		{
			cast->side_dist_x += cast->delta_dist_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist_y += cast->delta_dist_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}			
		if ((info->array_map[cast->map_x][cast->map_y] - '0') > 0)
			cast->hit = 1;
	}
}

void	ft_raydir_drw_handle(t_info *info, t_cast *cast)
{
	if (cast->side == 0 && cast->ray_dir_x > 0)
		cast->tex_x = info->sqw_width - cast->tex_x - 1;
	if (cast->side == 1 && cast->ray_dir_y < 0)
		cast->tex_x = info->sqw_width - cast->tex_x - 1;
}
