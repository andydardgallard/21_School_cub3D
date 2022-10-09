/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:42:30 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:50:13 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill(int j, int i, t_info *info)
{	
	if (info->arr_fullfil[j][i] != '0'
		&& info->arr_fullfil[j][i] != '2'
		&& info->arr_fullfil[j][i] != ' ')
		return (0);
	info->arr_fullfil[j][i] = 'z';
	if (i - 1 >= 0)
		ft_fullfill(j, i - 1, info);
	if (i + 1 < info->max_clmns)
		ft_fullfill(j, i + 1, info);
	if (j - 1 >= 0)
		ft_fullfill(j - 1, i, info);
	if (j + 1 < info->count_lines)
		ft_fullfill(j + 1, i, info);
	return (0);
}

int	ft_check_flfl_smbls(char c)
{
	if (c == 'z' || c == '0' || c == '2')
		return (1);
	else
		return (0);
}

int	ft_check_fullfil(t_info *info)
{
	int		i;
	int		j;
	int		cl;
	char	**arr;	

	cl = info->count_lines;
	arr = info->arr_fullfil;
	j = 0;
	while (j < cl)
	{
		if ((ft_check_flfl_smbls(arr[j][0]))
			|| ft_check_flfl_smbls(arr[j][info->max_clmns - 1]))
			return (1);
		j++;
	}
	i = 0;
	while (i < info->max_clmns)
	{
		if ((ft_check_flfl_smbls(arr[0][i]))
			|| ft_check_flfl_smbls(arr[cl - 1][i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_prmtr(t_info *info)
{
	int	j;
	int	i;

	if (!(ft_crt_arr_flfl(info)))
		ft_exit();
	j = 0;
	while (j < info->count_lines)
	{
		i = 0;
		while (i < info->max_clmns)
		{
			info->arr_fullfil[j][i] = info->array_map[j][i];
			i++;
		}		
		j++;
	}	
	ft_print_arr(info);
	ft_fullfill((int)(info->pos_x - .5), (int)(info->pos_y - .5), info);
	if ((ft_check_fullfil(info)))
		ft_exit();
	return (0);
}

int	ft_crt_arr_flfl(t_info *info)
{
	int	j;
	int	cnt;

	j = 0;
	cnt = info->count_lines + 1;
	info->arr_fullfil = (char **)malloc(sizeof(char *) * (cnt));
	if (!(info->arr_fullfil))
		return (0);
	info->arr_fullfil[info->count_lines] = NULL;
	while (j < info->count_lines)
	{
		info->arr_fullfil[j] = (char *)malloc(info->max_clmns + 1);
		if (!(info->arr_fullfil[j]))
			return (0);
		info->arr_fullfil[j][info->max_clmns] = '\0';
		j++;
	}	
	return (1);
}
