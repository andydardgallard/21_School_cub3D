/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_sort_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:40:46 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 15:56:25 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cnt_sprites(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->count_lines)
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == '2')
				info->num_sprites++;
			i++;
		}
		j++;
	}
}

int	ft_mas_sprites(t_info *info)
{	
	int	c;

	c = 0;
	info->sprite = (double **)malloc(sizeof(double *) * info->num_sprites);
	if (!(info->sprite))
		return (-1);
	while (c < info->num_sprites)
	{
		info->sprite[c] = (double *)malloc(sizeof(double) * 2);
		if (!(info->sprite[c]))
			return (-1);
		c++;
	}	
	c = 0;
	while (c < info->num_sprites)
	{
		ft_mas_check(info, c);
		c++;
	}
	return (0);
}

void	sort_order(t_pair *orders, int amount)
{
	int		i;
	int		j;
	t_pair	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}
