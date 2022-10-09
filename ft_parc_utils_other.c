/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:18:22 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:39:27 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_arr_cnt(char *for_cnt, int *cnt)
{
	while (*for_cnt != '\n')
	{
		*cnt += 1;
		for_cnt++;
	}
	for_cnt++;
	return (for_cnt);
}

void	ft_fill_arr(char *common, int *c, int *i, char *chr)
{
	if (common[*c] == '\n')
		*c += 1;
	*chr = common[*c];
	*i += 1;
	*c += 1;
}

void	ft_fill_array(t_info *info, char *common, int max)
{	
	int		j;
	int		i;
	int		c;
	int		cnt;	
	char	*for_cnt;	

	j = 0;
	c = 0;
	for_cnt = common;
	while (j < info->count_lines)
	{
		i = 0;
		cnt = 0;
		for_cnt = ft_fill_arr_cnt(for_cnt, &cnt);
		while (i < cnt)
			ft_fill_arr(common, &c, &i, &info->array_map[j][i]);
		while (i < max)
		{			
			info->array_map[j][i] = ' ';
			i++;
		}			
		j++;
	}	
}

void	ft_crt_common_buf(char **common, char **sln, t_info *info)
{
	*common = (char *)malloc(1);
	if (!(*common))
		info->error = 1;
	*common[0] = '\0';
	*sln = (char *)malloc(2);
	if (!(*sln))
		info->error = 1;
	*sln[0] = '\n';
	*sln[1] = '\0';
}

void	ft_check_desc_aftr_prc(t_info *info)
{
	if (info->width <= 0 || info->height <= 0 || info->floor_r < 0
		|| info->floor_g < 0 || info->floor_b < 0 || info->ceilling_r < 0
		|| info->ceilling_g < 0 || info->ceilling_b < 0
		|| info->no_path[0] == '\0' || info->we_path[0] == '\0'
		|| info->ea_path[0] == '\0' || info->so_path[0] == '\0'
		|| info->s_path[0] == '\0')
		info->error = 1;
}
