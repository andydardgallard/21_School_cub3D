/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils_clng.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:56 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:56:58 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_flr_cnt(char *line)
{
	int	cnt;

	cnt = 0;
	while (*line != '\0')
	{
		if (*line == ',')
			cnt++;
		line++;
	}	
	return (cnt);
}

void	ft_strncpy_path(char *src, int size, char path[], t_info *info)
{
	int	i;

	i = 0;
	while (i < size)
	{
		path[i] = src[i];
		i++;
	}
	path[i] = '\0';
	info->position = &path[i];
}

int	ft_cnt_max_width(int *maxs, char *common, t_info *info)
{
	int	i;
	int	cnt;
	int	max;

	i = 0;
	max = 0;
	while (i < info->count_lines)
	{
		cnt = 0;
		while (*common != '\n')
		{
			common++;
			cnt++;
		}
		maxs[i] = cnt;
		if (max == 0)
			max = maxs[i];
		else
			max = ft_cnt_max_i(max, maxs[i]);
		common++;
		i++;
	}
	return (max);
}

void	ft_exit(void)
{
	printf("error\n");
	exit(0);
}

int	ft_mas_check(t_info *info, int c)
{
	int	i;
	int	j;

	j = 0;
	while (info->array_map[j] != '\0')
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == '2')
			{
				info->sprite[c][0] = j + 0.5;
				info->sprite[c][1] = i + 0.5;
				info->array_map[j][i] = '0';
				return (1);
			}
			i++;
		}
		j++;
	}	
	return (0);
}
