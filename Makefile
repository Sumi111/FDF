# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:01:29 by sfathima          #+#    #+#              #
#    Updated: 2022/03/14 15:55:41 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
cc		= gcc
CFLAG	= -Wall -Werror -Wextra -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
RM		= rm -f

all:
	make -C libft
	make -C minilibx_macos
	$(cc) $(CFLAG) libft/libft.a code/main.c code/format.c code/plot.c code/map.c code/check.c  -o $(NAME)
	
clean	:
	make fclean -C libft 
	make clean -C minilibx_macos
	
fclean	: clean
	$(RM) $(NAME)

re		: fclean all