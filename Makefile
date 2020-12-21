# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 12:45:38 by ksharee           #+#    #+#              #
#    Updated: 2020/12/15 10:04:49 by ksharee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

SRCS			= ${wildcard *.c}

OBJS			= ${SRCS:.c=.o}

LIBFT 			= libft
MLX 			= minilibx

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror -g
LFLAGS			= -L libft -lft

METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				make -s -C $(MLX)
				mv $(MLX)/libmlx.dylib .
				make -s -C $(LIBFT)
				$(CC) $(CFLAGS) $(LFLAGS) $(METAL_MLX) -I . $(OBJS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -I . -o $@ -c $<

clean:
				$(RM) $(OBJS)
				make clean -C $(MLX)
				make clean -C $(LIBFT)

fclean:			clean
				$(RM) $(NAME)
				$(RM) libmlx.dylib
				make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
