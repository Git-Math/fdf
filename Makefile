#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/06 18:25:29 by mnguyen           #+#    #+#              #
#    Updated: 2015/02/10 18:57:21 by mnguyen          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FILES = ./srcs/color.c ./srcs/droite.c ./srcs/getnbr.c ./srcs/mlx.c \
		./srcs/error.c ./srcs/get_next_line.c ./srcs/lect.c \
		./srcs/main.c

LIB = cd ./libft; make re; cd ../../

LIBCLEAN = cd ./libft; make clean; cd ../../

LIBFCLEAN = cd ./libft; make fclean; cd ../../

LIBNAME = ./libft/libft.a

all : $(NAME)

$(NAME) : $(FILES)
	@$(LIB)
	@gcc $(FLAGS) -L/usr/X11/lib -lmlx -lXext -lX11 $(FILES) $(LIBNAME) -o $(NAME)

clean :
	@$(LIBCLEAN)

fclean : clean
	@$(LIBFCLEAN)
	@rm -f $(NAME)

re : fclean all