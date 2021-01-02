# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:25:57 by ksharee           #+#    #+#              #
#    Updated: 2021/01/01 23:31:47 by ksharee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D

PATH_INC	=	./inc
PATH_SRC	=	./src
PATH_OBJ	=	./obj
PATH_LIBFT	=	libft
PATH_LIBMLX	=	libmlx

SRCS		=	cub3d.c ft_putpixel.c get_next_line.c hook.c \
				pars_map.c raycast.c ft_error.c free_all.c rgb_color.c \
				pars_all.c pars_ceilling_color.c pars_floor_color.c pars_resolution.c pars_text.c \
				pars_player.c
OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
INCS		=	$(addprefix $(PATH_INC)/, cub3d.h)

COMP		=	gcc
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_ADD	=	-I$(PATH_INC)

RM			=	/bin/rm

all:		init $(NAME)

init:
	@ echo "$(_INFO) Initialize $(NAME)"
	@ $(shell mkdir -p $(PATH_OBJ))
	@ make -C $(PATH_LIBFT)
	@ make -C $(PATH_LIBMLX)

$(NAME):	$(OBJS) $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ make -C $(PATH_LIBFT) clean
	@ make -C $(PATH_LIBMLX) clean
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)
	@ make -C $(PATH_LIBFT) fclean

re: fclean all
