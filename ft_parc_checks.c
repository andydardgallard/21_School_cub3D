/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:22:58 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:45:27 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_smbls(char c)
{
	if (c != ' ' && c != '\t')
		return (1);
	return (0);
}

int	ft_check_smbls_tail(char c)
{	
	if (c != ' ' && c != '\t' && c != '\n' && c != '\0')
		return (1);
	return (0);
}

int	ft_check_map_smbls(char *str)
{
	char	*check;

	check = str;
	while (*check != '\0')
	{		
		if (*check != '1' && *check != '0' && *check != '2'
			&& *check != 'N' && *check != 'E' && *check != 'W'
			&& *check != 'S' && *check != ' ' && *check != '\t')
			return (0);
		else if (*check == '\n')
			return (0);
		check++;
	}
	return (1);
}

int	ft_check_tail(char *end)
{
	int		i;
	char	*str;	

	str = ft_strchr(end, 'm');
	i = 0;
	str++;
	if (ft_strlen(end) > 4)
	{	
		while (str[i] != '\0')
		{
			if ((ft_check_smbls_tail(str[i])))
				return (1);
			i++;
		}
	}	
	return (0);
}

void	ft_check_plr_smbls(char *common, t_info *info)
{
	int	i;

	i = 0;
	while (*common != '\0')
	{
		if (*common == 'N' || *common == 'E'
			|| *common == 'W' || *common == 'S')
			i++;
		common++;
	}
	if (i == 0)
		info->error = 1;
}
