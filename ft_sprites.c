/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:38:47 by dgallard          #+#    #+#             */
/*   Updated: 2021/04/27 15:39:45 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprites_draw_handle(t_sprt_drw *sprt_drw, t_info *info)
{
	int	d;
	int	y;
	int	color;

	y = sprt_drw->draw_start_y;
	while (y < sprt_drw->draw_end_y)
	{
		d = (y - sprt_drw->v_move_screen) * 256 - info->height
			* 128 + sprt_drw->sprite_height * 128;
		sprt_drw->tex_y = ((d * info->sqw_height)
				/ sprt_drw->sprite_height) / 256;
		color = info->texture[4]
		[info->sqw_width * sprt_drw->tex_y + sprt_drw->tex_x];
		if ((color & 0xFFFFFF) != 0)
			info->buf[y][sprt_drw->stripe] = color;
		y++;
	}
}

void	ft_sprites_draw_helper(t_sprt_drw *sprt_drw, t_info *info)
{
	sprt_drw->stripe = sprt_drw->draw_start_x;
	while (sprt_drw->stripe < sprt_drw->draw_end_x)
	{
		sprt_drw->tex_x = (int)((256 * (sprt_drw->stripe
						- (-sprt_drw->sprite_width / 2
							+ sprt_drw->sprite_screen_x))
					* info->sqw_width / sprt_drw->sprite_width) / 256);
		if (sprt_drw->transform_y > 0 && sprt_drw->stripe > 0
			&& sprt_drw->stripe < info->width && sprt_drw->transform_y
			< info->zBuffer[sprt_drw->stripe])
			ft_sprites_draw_handle(sprt_drw, info);
		sprt_drw->stripe++;
	}		
}

void	ft_sprite_param_calc(t_sprt_drw *sprt_drw, t_info *info)
{
	sprt_drw->draw_start_y = -sprt_drw->sprite_height / 2
		+ info->height / 2 + sprt_drw->v_move_screen;
	if (sprt_drw->draw_start_y < 0)
		sprt_drw->draw_start_y = 0;
	sprt_drw->draw_end_y = sprt_drw->sprite_height / 2
		+ info->height / 2 + sprt_drw->v_move_screen;
	if (sprt_drw->draw_end_y >= info->height)
		sprt_drw->draw_end_y = info->height - 1;
	sprt_drw->sprite_width = (int)fabs((info->height / sprt_drw->transform_y));
	sprt_drw->draw_start_x = -sprt_drw->sprite_width / 2
		+ sprt_drw->sprite_screen_x;
	if (sprt_drw->draw_start_x < 0)
		sprt_drw->draw_start_x = 0;
	sprt_drw->draw_end_x = sprt_drw->sprite_width / 2
		+ sprt_drw->sprite_screen_x;
	if (sprt_drw->draw_end_x >= info->width)
		sprt_drw->draw_end_x = info->width - 1;
}

void	ft_sprites_draw(t_info *info)
{
	int			i;
	t_sprt_drw	sprt_drw;	

	i = 0;
	while (i < info->num_sprites)
	{		
		sprt_drw.sprite_x = info->sprite[info->sprite_order[i]][0]
			- info->pos_x;
		sprt_drw.sprite_y = info->sprite[info->sprite_order[i]][1]
			- info->pos_y;
		sprt_drw.inv_det = 1.0 / (info->plane_x
				* info->dir_y - info->dir_x * info->plane_y);
		sprt_drw.transform_x = sprt_drw.inv_det * (info->dir_y
				* sprt_drw.sprite_x - info->dir_x * sprt_drw.sprite_y);
		sprt_drw.transform_y = sprt_drw.inv_det * (-info->plane_y
				* sprt_drw.sprite_x + info->plane_x * sprt_drw.sprite_y);
		sprt_drw.sprite_screen_x = (int)((info->width / 2)
				* (1 + sprt_drw.transform_x / sprt_drw.transform_y));
		sprt_drw.v_move_screen = (int)(0.0 / sprt_drw.transform_y);
		sprt_drw.sprite_height = (int)fabs((
					info->height / sprt_drw.transform_y));
		ft_sprite_param_calc(&sprt_drw, info);
		ft_sprites_draw_helper(&sprt_drw, info);
		i++;
	}
}

void	ft_sprites_calc(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_sprites)
	{		
		info->sprite_order[i] = i;
		info->sprite_distance[i] = ((info->pos_x - info->sprite[i][0])
				* (info->pos_x - info->sprite[i][0])
				+ (info->pos_y - info->sprite[i][1])
				* (info->pos_y - info->sprite[i][1]));
		i++;
	}	
	sortSprites(info->sprite_order, info->sprite_distance, info->num_sprites);
	ft_sprites_draw(info);
}
