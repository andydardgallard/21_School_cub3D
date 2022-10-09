/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:16:05 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/26 14:25:14 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_la_update(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	old_plane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(info->rotSpeed)
		- info->dir_y * sin(info->rotSpeed);
	info->dir_y = old_dir_x * sin(info->rotSpeed)
		+ info->dir_y * cos(info->rotSpeed);
	info->plane_x = info->plane_x * cos(info->rotSpeed)
		- info->plane_y * sin(info->rotSpeed);
	info->plane_y = old_plane_x * sin(info->rotSpeed)
		+ info->plane_y * cos(info->rotSpeed);
}

void	key_update(t_info *info)
{
	if (info->key_w)
		key_w_update(info);
	if (info->key_s)
		key_s_update(info);
	if (info->key_a)
		key_a_update(info);
	if (info->key_d)
		key_d_update(info);
	if (info->key_ra)
		ft_ra_update(info);
	if (info->key_la)
		ft_la_update(info);
	if (info->key_esc)
		exit(0);
}

int	key_press(int key, t_info *info)
{
	(void) info;
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 1;
	else if (key == 0)
		info->key_a = 1;
	else if (key == 1)
		info->key_s = 1;
	else if (key == 2)
		info->key_d = 1;
	else if (key == 123)
		info->key_la = 1;
	else if (key == 124)
		info->key_ra = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	(void) info;
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 0;
	else if (key == 0)
		info->key_a = 0;
	else if (key == 1)
		info->key_s = 0;
	else if (key == 2)
		info->key_d = 0;
	else if (key == 123)
		info->key_la = 0;
	else if (key == 124)
		info->key_ra = 0;
	return (0);
}

int	close_wind(void)
{
	exit(0);
	return (0);
}
