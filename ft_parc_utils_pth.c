/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils_pth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:57:10 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:57:13 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_write_clng(char *line, t_info *info)
{
	int	i;
	int	cnt;

	cnt = 0;
	ft_flr_check_bfr_nmbr(line, info);
	cnt = ft_flr_cnt(line);
	if (cnt != 2)
		ft_exit();
	info->ceilling_r = ft_atoi_flr(++line, info);
	ft_flr_check_cmm(info);
	info->position = ft_strchr(info->position, ',');
	info->ceilling_g = ft_atoi_flr(++info->position, info);
	ft_flr_check_cmm(info);
	info->position = ft_strchr(info->position, ',');
	info->ceilling_b = ft_atoi_flr(++info->position, info);
	i = 0;
	while (info->position[i] != '\0')
	{
		if (ft_check_smbls(info->position[i]))
			info->error = 1;
		i++;
	}	
	return (0);
}

void	ft_chcks_plr_pstn(t_info *info, int i, int j)
{
	info->pos_x = j + .5;
	info->pos_y = i + .5;
	if (info->array_map[j][i] == 'S')
		ft_fill_s_pstn(info);
	else if (info->array_map[j][i] == 'E')
		ft_fill_e_pstn(info);
	else if (info->array_map[j][i] == 'W')
		ft_fill_w_pstn(info);
	else if (info->array_map[j][i] == 'N')
		ft_fill_n_pstn(info);
	info->array_map[j][i] = '0';
}

int	ft_cnt_max_i(int max, int maxs)
{
	if (max < maxs)
		return (max = maxs);
	else
		return (max);
}

void	ft_parc_fnd_ones(t_info *info, char **common, char *spec, char *sln)
{
	*common = ft_strjoin_free(*common, spec);
	*common = ft_strjoin_free(*common, sln);
	info->count_lines++;
	info->map_flag = 1;
}

void	ft_parc_map(t_info *info, char *spec, char **common, char *sln)
{
	if (!(ft_check_map_smbls(spec)))
		info->error = 1;
	else if (info->map_flag == 1)
	{		
		if (spec[0] == '\0')
			info->map_flag_spcs = 1;
		if ((ft_strchr(spec, '1')) && info->map_flag_spcs == 1)
			info->error = 1;
		else
		{
			if (spec[0] != '\0' )
			{
				*common = ft_strjoin_free(*common, spec);
				*common = ft_strjoin_free(*common, sln);
				info->count_lines++;
			}
			else
				info->error = 1;
		}
	}
	else if ((ft_strchr(spec, '1')))
		ft_parc_fnd_ones(info, common, spec, sln);
}
