/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:57:01 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 16:25:56 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_bitmap54(t_info *info)
{
	static char	bitmap[54];

	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = info->width * info->height * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = (int)info->width;
	*(int *)(bitmap + 22) = (int)info->height;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	return ((void *)bitmap);
}

int	create_clean_file(const char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		write(2, "ERROR: can't create file\n", 25);
	return (fd);
}

void	write_img(int fd, t_info *info)
{
	int				y;
	int				x;	
	unsigned int	color;

	y = info->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->width)
		{
			color = info->buf[y][x];
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void	ft_doscreenshot(t_info *info)
{
	int		fd;
	void	*bitmap;

	bitmap = init_bitmap54(info);
	fd = create_clean_file("screenshot.bmp");
	write(fd, bitmap, 54);
	calc(info);
	draw(info);
	write_img(fd, info);
}
