# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:25:57 by ksharee           #+#    #+#              #
#    Updated: 2021/01/07 00:49:34 by ksharee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
NAME_BONUS		=	cub3d_bonus

PATH_INC		=	./inc
PATH_SRC		=	./src
PATH_SRC_BONUS	=	./bonus
PATH_OBJ		=	./obj
PATH_LIBFT		=	libft
PATH_LIBMLX		=	libmlx

SRCS			=	cub3d.c ft_putpixel.c get_next_line.c hook.c \
					pars_map.c raycast.c ft_error.c free_all.c rgb_color.c \
					pars_all.c pars_ceilling_color.c pars_floor_color.c pars_resolution.c pars_text.c \
					pars_player.c pars_sprites.c draw_sprites.c draw_sprites2.c save_bitmap.c \
					pars_map2.c raycast2.c ft_isnum.c
SRCS_BONUS		=	cub3d_bonus.c ft_putpixel_bonus.c get_next_line_bonus.c hook_bonus.c \
					pars_map_bonus.c raycast_bonus.c ft_error_bonus.c free_all_bonus.c rgb_color_bonus.c \
					pars_all_bonus.c pars_ceilling_color_bonus.c pars_floor_color_bonus.c pars_resolution_bonus.c pars_text_bonus.c \
					pars_player_bonus.c pars_sprites_bonus.c draw_sprites_bonus.c draw_sprites2_bonus.c save_bitmap_bonus.c \
					pars_map2_bonus.c raycast2_bonus.c ft_isnum_bonus.c
OBJS			=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix $(PATH_OBJ)/, $(SRCS_BONUS:.c=.o))
INCS			=	$(addprefix $(PATH_INC)/, cub3d.h)
INCS_BONUS		=	$(addprefix $(PATH_INC)/, cub3d_bonus.h)

COMP			=	gcc
COMP_FLAG		=	-Wall -Werror -Wextra
COMP_ADD		=	-I$(PATH_INC)

RM				=	/bin/rm

all:			init $(NAME)

bonus:			init $(NAME_BONUS)

init:
	@ echo "$(_INFO) Initialize $(NAME)"
	@ $(shell mkdir -p $(PATH_OBJ))
	@ make -C $(PATH_LIBFT)
	@ make -C $(PATH_LIBMLX)

$(NAME_BONUS):	$(OBJS_BONUS) $(INCS_BONUS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME_BONUS) $(OBJS_BONUS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(PATH_OBJ)/%.o: $(PATH_SRC_BONUS)/%.c $(INCS_BONUS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

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
	@ $(RM) -rf $(NAME) $(NAME_BONUS) screen.bmp
	@ make -C $(PATH_LIBFT) fclean

re: fclean all
