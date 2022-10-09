/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:23:49 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 20:46:13 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_after_parc(t_info *info, char *common)
{
	int	j;

	ft_check_desc_aftr_prc(info);
	ft_check_plr_smbls(common, info);
	info->maxs = (int *)malloc(sizeof(int) * info->count_lines);
	if (!(info->maxs))
		info->error = 1;
	info->max_clmns = ft_cnt_max_width(info->maxs, common, info);
	j = 0;
	info->array_map = (char **)malloc(sizeof(char *) * (info->count_lines + 1));
	info->array_map[info->count_lines] = NULL;
	while (j < info->count_lines)
	{
		info->array_map[j] = (char *)malloc(info->max_clmns + 1);
		info->array_map[j][info->max_clmns] = '\0';
		j++;
	}	
	ft_fill_array(info, common, info->max_clmns);
	if (info->error == 1)
	{		
		printf("map_error\n");
		exit (0);
	}	
}

void	ft_check_path(char *path, t_info *info, char *line,
								void (*f)(char *, t_info *))
{
	if (path[0] != '\0')
		info->error = 1;
	f(line, info);
}

void	ft_gnl_inside(t_info *info, char **line, char	**common, char **sln)
{
	char	*spec;

	if ((ft_check_desc_ones(info)))
		ft_parc_map(info, spec = *line, common, *sln);
	else if (ft_strchr(*line, 'R'))
		ft_parc_r(spec = *line, *line, info);
	else if (ft_strchr(*line, 'F'))
		ft_parc_f(spec = *line, *line, info);
	else if (ft_strchr(*line, 'C'))
		ft_parc_c(spec = *line, *line, info);
	else if (ft_strchr(*line, 'N'))
		ft_check_path(info->no_path, info, *line, &ft_parc_n);
	else if (ft_strchr(*line, 'W'))
		ft_check_path(info->we_path, info, *line, &ft_parc_w);
	else if (ft_strchr(*line, 'E'))
		ft_check_path(info->ea_path, info, *line, &ft_parc_e);
	else if (ft_strchr(*line, 'S'))
		ft_parc_s(spec = *line, *line, info);
}

void	ft_parc(int fd, t_info *info)
{
	char	*line;
	int		gnl;
	char	*common;
	char	*sln;

	gnl = 1;
	ft_crt_common_buf(&common, &sln, info);
	while (gnl > 0)
	{
		gnl = ft_gnl(&line, fd, info);
		ft_gnl_inside(info, &line, &common, &sln);
		free(line);
	}
	ft_after_parc(info, common);
	free(common);
	free(sln);
}
