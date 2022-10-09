# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 14:58:16 by dgallard          #+#    #+#              #
#    Updated: 2021/04/27 21:52:11 by dgallard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a

SRCS		= 	ft_strlen.c ft_strchr.c ft_strncmp.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		= 	-Wall -Werror -Wextra

INCS		= 	./

.c.o:
			@gcc $(CFLAGS) -I$(INCS) -c $< -o $(<:.c=.o)


all:		$(NAME)

$(NAME): 	$(OBJS) libft.h
			@ar rcs $(NAME) $(OBJS)
			@echo "--------Make libft.a done successfully-----------"
			
clean:
			@rm -f $(OBJS)
			@echo "--------Removed libft object files---------------"

fclean: 	clean
			@rm -f $(NAME)
			@echo "--------Removed libft bin files------------------"

re: 		fclean all
			@echo "--------Remake libft.a done successfully--------"

.PHONY:		all clean fclean re
