/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:02:28 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/24 19:40:48 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_desc_ones(t_info *info)
{
	if (info->width > 0 && info->height > 0 && info->floor_r >= 0
		&& info->floor_g >= 0 && info->floor_b >= 0 && info->ceilling_r >= 0
		&& info->ceilling_g >= 0 && info->ceilling_b >= 0
		&& info->no_path[0] != '\0' && info->we_path[0] != '\0'
		&& info->ea_path[0] != '\0' && info->so_path[0] != '\0'
		&& info->s_path[0] != '\0')
		return (1);
	else
		return (0);
}

void	ft_parc_r(char *spec, char *line, t_info *info)
{
	while (spec != ft_strchr(line, 'R'))
	{		
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}		
	if (info->width != -1 || info->height != -1)
		info->error = 1;
	else
		ft_write_resltn(ft_strchr(line, 'R'), info);
}

void	ft_parc_f(char *spec, char *line, t_info *info)
{
	while (spec != ft_strchr(line, 'F'))
	{
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}	
	if (info->floor_r != -1 || info->floor_g != -1 || info->floor_b != -1)
		info->error = 1;
	else
		ft_write_flr(ft_strchr(line, 'F'), info);
}

void	ft_parc_c(char *spec, char *line, t_info *info)
{
	while (spec != ft_strchr(line, 'C'))
	{
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}
	if (info->ceilling_r != -1
		|| info->ceilling_g != -1 || info->ceilling_b != -1)
		info->error = 1;
	else
		ft_write_clng(ft_strchr(line, 'C'), info);
}
