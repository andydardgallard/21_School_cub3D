/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:47:59 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 21:04:25 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_front(int j, int i, t_info *info)
{		
	if (info->arr_fullfil[j][i] == ' ')
	{			
		if (i - 1 >= 0)
		{
			if (info->arr_fullfil[j][i - 1] == '0' )
				return (1);
		}		
		if (i + 1 < info->max_clmns)
		{
			if (info->arr_fullfil[j][i + 1] == '0' )
				return (1);
		}		
		if (j - 1 >= 0)
		{
			if (info->arr_fullfil[j - 1][i] == '0')
				return (1);
		}		
		if (j + 1 < info->count_lines)
		{
			if (info->arr_fullfil[j + 1][i] == '0')
				return (1);
		}
	}		
	return (0);
}

void	ft_print_arr(t_info *info)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	while (j < info->count_lines)
	{
		i = 0;
		while (i < info->max_clmns)
		{
			check = ft_check_front(j, i, info);
			if (check == 1)
				ft_exit();
			i ++;
		}		
		j++;
	}
}
