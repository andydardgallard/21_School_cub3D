/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:33:50 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/24 14:30:09 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	int		len_joined;
	char	*strjoined;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len_joined = ft_strlen(str1) + ft_strlen(str2);
	strjoined = (char *)malloc(len_joined + 1);
	if (!(strjoined))
		return (NULL);
	len_str1 = 0;
	len_str2 = 0;
	len_joined = 0;
	while (str1[len_str1] != '\0')
		strjoined[len_joined++] = str1[len_str1++];
	while (str2[len_str2] != '\0')
		strjoined[len_joined++] = str2[len_str2++];
	strjoined[len_joined] = '\0';
	free(str1);
	return (strjoined);
}

int	ft_gnl(char **line, int fd, t_info *info)
{
	int		rd;
	char	buf[2];

	rd = 1;
	*line = (char *)malloc(1);
	if (!(*line))
		info->error = 1;
	*line[0] = '\0';
	while ((rd != 0))
	{
		rd = read(fd, buf, 1);
		if (rd == -1)
		{
			info->error = 1;
			return (-1);
		}			
		buf[rd] = '\0';
		if (buf[0] == '\n')
			return (1);
		*line = ft_strjoin_free(*line, buf);
	}
	if (info->error == 1)
		return (-1);
	return (0);
}

int	ft_atoi_resltn(char *str, t_info *info)
{
	size_t			i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if ((res > 2147483647) && sign == (-1))
			res = -1;
		if (res > 2147483647)
			res = 2147483647;
	}
	info->position = &str[i];
	return ((int)(sign * res));
}

int	ft_atoi_flr(char *str, t_info *info)
{
	size_t			i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if ((res > 255) && sign == (-1))
			res = -1;
		if (res > 255)
			res = -1;
	}
	info->position = &str[i];
	return ((int)(sign * res));
}

int	ft_strlen_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (i);
}
