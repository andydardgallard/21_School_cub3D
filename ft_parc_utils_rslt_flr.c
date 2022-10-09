/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils_rslt_flr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:33:13 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:38:28 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_max_rsltn(t_info *info)
{
	int	max_size_x;
	int	max_size_y;

	mlx_get_screen_size(&max_size_x, &max_size_y);
	if (info->width > max_size_x)
		info->width = max_size_x;
	if (info->height > max_size_y)
		info->height = max_size_y;
}

int	ft_write_resltn(char *line, t_info *info)
{
	int	i;

	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] > ' ' && (line[i] < '-' || line[i] > '9'))
		{
			info->error = 1;
			return (0);
		}		
		i++;
	}	
	info->width = ft_atoi_resltn(++line, info);
	info->height = ft_atoi_resltn(++info->position, info);
	i = 0;
	while (info->position[i] != '\0')
	{		
		if (ft_check_smbls(info->position[i]))
			info->error = 1;
		i++;
	}	
	if (info->screenshot == 0)
		ft_max_rsltn(info);
	return (0);
}

void	ft_flr_check_cmm(t_info *info)
{
	int	i;

	i = 0;
	while (info->position[i] != ',')
	{		
		if (info->position[i] != ' ' && info->position[i] != '\t')
			info->error = 1;
		i++;
	}	
}

void	ft_flr_check_bfr_nmbr(char *line, t_info *info)
{
	int	i;

	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] != ',' && line[i] > ' '
			&& (line[i] < '-' || line[i] > '9'))
			info->error = 1;
		i++;
	}	
}

int	ft_write_flr(char *line, t_info *info)
{
	int	i;
	int	cnt;

	cnt = 0;
	ft_flr_check_bfr_nmbr(line, info);
	cnt = ft_flr_cnt(line);
	if (cnt != 2)
		ft_exit();
	info->floor_r = ft_atoi_flr(++line, info);
	ft_flr_check_cmm(info);
	info->position = ft_strchr(info->position, ',');
	info->floor_g = ft_atoi_flr(++info->position, info);
	ft_flr_check_cmm(info);
	info->position = ft_strchr(info->position, ',');
	info->floor_b = ft_atoi_flr(++info->position, info);
	i = 0;
	while (info->position[i] != '\0')
	{
		if (ft_check_smbls(info->position[i]))
			info->error = 1;
		i++;
	}
	return (0);
}
