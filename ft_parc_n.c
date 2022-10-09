/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:38:26 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:44:00 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_parc_utils_one(char *spec, char *line, t_info *info, char c)
{
	while (spec != ft_strchr(line, c))
	{
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}				
	spec++;
	return (spec);
}

char	*ft_parc_utils_two(char *spec, char *end, t_info *info, char *path)
{	
	while (spec != end)
	{
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}					
	ft_strncpy_path(end, ft_strlen_path(end), path, info);
	return (spec);
}

char	*ft_parc_utils_three(char *spec, char *slh, t_info *info, char *path)
{	
	while (spec != slh)
	{
		if (ft_check_smbls(spec[0]))
			info->error = 1;
		spec++;
	}							
	ft_strncpy_path(slh, ft_strlen_path(slh), path, info);
	return (spec);
}

char	*ft_parc_utils_four(char *spec, char *line, t_info *info, char c)
{
	while (spec != ft_strchr(line, c))
	{		
		if (ft_check_smbls(spec[0]))
		{
			info->error = 1;
			free(line);
			printf("map_error\n");
			exit(0);
		}		
		spec++;
	}				
	spec++;
	return (spec);
}

void	ft_parc_n(char *line, t_info *info)
{
	char	*end;
	char	*slh;
	char	*spec;

	spec = line;
	spec = ft_parc_utils_one(spec, line, info, 'N');
	if (*spec == 'O')
	{
		end = ft_strchr(spec++, '.');
		slh = ft_strchr(spec, '/');
		if (end && slh)
		{
			ft_kstl(slh);
			if (slh - end > 0)
				spec = ft_parc_utils_two(spec, end, info, info->no_path);
			else
				spec = ft_parc_utils_three(spec, slh, info, info->no_path);
		}
		else
			info->error = 1;
	}
	else
		info->error = 1;
}
