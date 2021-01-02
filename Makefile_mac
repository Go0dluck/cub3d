# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 12:45:38 by ksharee           #+#    #+#              #
#    Updated: 2020/12/29 14:49:51 by ksharee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D

PATH_INC	=	./inc
PATH_SRC	=	./src
PATH_OBJ	=	./obj
PATH_LIBFT	=	libft
PATH_LIBMLX	=	minilibx

SRCS		=	cub3d.c ft_putpixel.c get_next_line.c hook.c parser.c raycast.c texture.c
OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
INCS		=	$(addprefix $(PATH_INC)/, cub3d.h)

COMP		=	gcc
COMP_FLAG	=	-Wall -Werror -Wextra -g
COMP_ADD	=	-I$(PATH_INC)

METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit

RM				= rm -rf

all:			init $(NAME)

init:
				echo "$(_INFO) Initialize $(NAME)"
				$(shell mkdir -p $(PATH_OBJ))
				make -C $(PATH_LIBFT)
				make -C $(PATH_LIBMLX)
				mv $(PATH_LIBMLX)/libmlx.dylib .

$(NAME):		$(OBJS) $(INCS)
				$(COMP) $(CFLAGS) $(COMP_ADD) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx $(METAL_MLX)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INCS)
				$(CC) $(CFLAGS) -I . -o $@ -c $<

clean:
				$(RM) $(PATH_OBJ)
				make -C $(PATH_LIBFT) clean
				make -C $(PATH_LIBMLX) clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) libmlx.dylib
				make -C $(PATH_LIBFT) fclean

re:				fclean all

.PHONY: 		all fclean clean re
