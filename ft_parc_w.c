/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:00:05 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:37:43 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parc_w(char *line, t_info *info)
{
	char	*end;
	char	*slh;
	char	*spec;

	spec = line;
	spec = ft_parc_utils_one(spec, line, info, 'W');
	if (*spec == 'E')
	{
		end = ft_strchr(spec++, '.');
		slh = ft_strchr(spec, '/');
		if (end && slh)
		{			
			if ((ft_check_tail(ft_strchr(slh, '.'))))
				info->error = 1;
			if (slh - end > 0)
				spec = ft_parc_utils_two(spec, end, info, info->we_path);
			else
				spec = ft_parc_utils_three(spec, slh, info, info->we_path);
		}	
		else
			info->error = 1;
	}
	else
		info->error = 1;
}

void	ft_kstl(char *slh)
{
	if (!(ft_strchr(slh, '.')))
		ft_exit();
	if ((ft_check_tail(ft_strchr(slh, '.'))))
		ft_exit();
}

void	ft_parc_e(char *line, t_info *info)
{
	char	*end;
	char	*slh;
	char	*spec;

	spec = line;
	spec = ft_parc_utils_one(spec, line, info, 'E');
	if (*spec == 'A')
	{
		end = ft_strchr(spec++, '.');
		slh = ft_strchr(spec, '/');
		if (end && slh)
		{
			ft_kstl(slh);
			if (slh - end > 0)
				spec = ft_parc_utils_two(spec, end, info, info->ea_path);
			else
				spec = ft_parc_utils_three(spec, slh, info, info->ea_path);
		}	
		else
			info->error = 1;
	}
	else
		info->error = 1;
}

void	ft_parc_sprite(char *spec, t_info *info)
{
	char	*end;
	char	*slh;

	if (info->s_path[0] != '\0')
		info->error = 1;
	end = ft_strchr(spec, '.');
	slh = ft_strchr(spec, '/');
	if (end && slh)
	{
		if (!(ft_strchr(slh, '.')))
			ft_exit();
		if ((ft_check_tail(ft_strchr(slh, '.'))))
			info->error = 1;
		if (slh - end > 0)
			spec = ft_parc_utils_two(spec, end, info, info->s_path);
		else
			spec = ft_parc_utils_three(spec, slh, info, info->s_path);
	}
	else
		info->error = 1;
}

void	ft_parc_s(char *spec, char *line, t_info *info)
{
	char	*end;
	char	*slh;

	spec = line;
	spec = ft_parc_utils_four(spec, line, info, 'S');
	if (*spec == 'O')
	{
		if (info->so_path[0] != '\0')
			info->error = 1;
		end = ft_strchr(spec++, '.');
		slh = ft_strchr(spec, '/');
		if (end && slh)
		{
			ft_kstl(slh);
			if (slh - end > 0)
				spec = ft_parc_utils_two(spec, end, info, info->so_path);
			else
				spec = ft_parc_utils_three(spec, slh, info, info->so_path);
		}
		else
			ft_exit();
	}
	else
		ft_parc_sprite(spec, info);
}
