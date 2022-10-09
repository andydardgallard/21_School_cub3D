/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck_strt_plr_pstn.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:20 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:56:23 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_s_pstn(t_info *info)
{
	info->dir_x = 1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = -0.66;
	info->start_pos = 'S';
}

void	ft_fill_e_pstn(t_info *info)
{
	info->dir_x = 0.0;
	info->dir_y = 1.0;
	info->plane_x = 0.66;
	info->plane_y = 0;
	info->start_pos = 'E';
}

void	ft_fill_w_pstn(t_info *info)
{
	info->dir_x = 0.0;
	info->dir_y = -1.0;
	info->plane_x = -0.66;
	info->plane_y = 0;
	info->start_pos = 'W';
}

void	ft_fill_n_pstn(t_info *info)
{
	info->dir_x = -1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.66;
	info->start_pos = 'N';
}

void	check_start_plr_position(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (info->array_map[j] != '\0')
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == 'N' || info->array_map[j][i] == 'S' ||
				info->array_map[j][i] == 'W' || info->array_map[j][i] == 'E')
			{
				ft_chcks_plr_pstn(info, i, j);
				break ;
			}			
			i++;
		}			
		j++;
	}	
}
