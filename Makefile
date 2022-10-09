# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 19:33:28 by dgallard          #+#    #+#              #
#    Updated: 2021/04/27 21:50:41 by dgallard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	cub3D

SRCS		= 	ft_parc.c cub.c ft_gnl.c ft_parc_utils.c ft_crt_sort_sprites.c \
				ft_screenshot.c ft_check_map_sp.c ft_parc_utils_other.c ft_bufs_crt.c \
				ft_keys_update.c ft_keys_handle.c ft_init.c ft_calc.c ft_sprites.c \
				ft_calc_helper.c ft_fullfil.c ft_parc_utils_pth.c ft_chck_strt_plr_pstn.c \
				ft_parc_w.c ft_parc_n.c ft_parc_utils_rslt_flr.c ft_parc_utils_clng.c ft_parc_checks.c

OBJS		= 	$(SRCS:.c=.o)

LIBFT		= ./libft/libft.a

CFLAGS		= 	-Wall -Werror -Wextra

MLXFLAGS	=	libmlx.a -framework OpenGL -framework Appkit

INCS		= 	./

.c.o:
			@gcc $(CFLAGS) -I$(INCS) -c $< -o $(<:.c=.o)


all:		$(LIBFT) $(NAME)
			

$(NAME): 	$(OBJS) cub3d.h
			@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME) 
			@echo "--------Make cub3D done successfully-------------------"

$(LIBFT):
			$(MAKE) -C libft
			
clean:
			@rm -f $(OBJS)
			$(MAKE) clean -C libft
			@echo "--------Removed cub3D object files----------------------"

fclean: 	clean
			@rm -f $(NAME)
			$(MAKE) fclean -C libft
			@echo "--------Removed cub3D bin files-------------------------"

re: 		fclean all
			@echo "--------Remake cub3D done successfully-----------------"

.PHONY:		all clean fclean re
