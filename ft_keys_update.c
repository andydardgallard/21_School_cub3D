/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:38:04 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/26 14:13:43 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w_update(t_info *info)
{
	if (!(info->array_map[(int)(info->pos_x + 2 * info->dir_x
				* info->movespeed)][(int)(info->pos_y)] - '0'))
		info->pos_x += info->dir_x * info->movespeed;
	if (!(info->array_map[(int)(info->pos_x)][(int)(info->pos_y + 3
		* info->dir_y * info->movespeed)] - '0'))
		info->pos_y += info->dir_y * info->movespeed;
}

void	key_s_update(t_info *info)
{
	if (!(info->array_map[(int)(info->pos_x - 2 * info->dir_x
				* info->movespeed)][(int)(info->pos_y)] - '0'))
		info->pos_x -= info->dir_x * info->movespeed;
	if (!(info->array_map[(int)(info->pos_x)][(int)(info->pos_y - 2
		* info->dir_y * info->movespeed)] - '0'))
		info->pos_y -= info->dir_y * info->movespeed;
}

void	key_a_update(t_info *info)
{
	if (!(info->array_map[(int)(info->pos_x - 2 * info->dir_y
				* info->movespeed)][(int)info->pos_y] - '0'))
		info->pos_x -= info->dir_y * info->movespeed;
	if (!(info->array_map[(int)info->pos_x][(int)(info->pos_y + 2
			* info->dir_x * info->movespeed)] - '0'))
		info->pos_y += info->dir_x * info->movespeed;
}

void	key_d_update(t_info *info)
{
	if (!(info->array_map[(int)(info->pos_x + 2 * info->dir_y
				* info->movespeed)][(int)info->pos_y] - '0'))
		info->pos_x += info->dir_y * info->movespeed;
	if (!(info->array_map[(int)info->pos_x][(int)
			(info->pos_y - 2 * info->dir_x * info->movespeed)] - '0'))
		info->pos_y -= info->dir_x * info->movespeed;
}

void	ft_ra_update(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	old_plane_x = info->plane_x;
	if (info->key_ra)
	{	
		info->dir_x = info->dir_x * cos(-info->rotSpeed)
			- info->dir_y * sin(-info->rotSpeed);
		info->dir_y = old_dir_x * sin(-info->rotSpeed)
			+ info->dir_y * cos(-info->rotSpeed);
		info->plane_x = info->plane_x * cos(-info->rotSpeed)
			- info->plane_y * sin(-info->rotSpeed);
		info->plane_y = old_plane_x * sin(-info->rotSpeed)
			+ info->plane_y * cos(-info->rotSpeed);
	}	
}
