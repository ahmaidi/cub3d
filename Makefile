# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 07:24:22 by mboukhal          #+#    #+#              #
#    Updated: 2022/10/15 14:14:28 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all

NAME				= cub3d
BONUS				= cub3d_bonus

OPTION				= -Wall -Wextra -Werror #-g -fsanitize=address 

S					= src/
B					= bonus/
P					= $(S)parsing/

INCLUDES			= -I /usr/local/include -I includes/ -lmlx -I $(s)libft/ \
					  -L /usr/local/lib/ -framework OpenGL \
					  -framework AppKit

MAIN_FILES			= $(S)main.c $(P)checks.c $(P)alloc.c $(S)key_manip.c $(S)drow.c $(P)check_str.c \
					  $(S)key_func.c $(S)cast_rays.c $(S)rays_calc.c $(S)3d_pjection.c \
					  $(P)parsing_utils_2.c $(P)parsing_utils_1.c $(P)transform_map.c \
					  $(S)get_next_line/get_next_line.c $(P)get_texture_color.c $(P)free_it.c \
					  $(S)get_next_line/get_next_line_utils.c $(P)valid_map.c $(P)init.c \
					  $(S)vert_ray.c $(S)horz_ray.c \

CFILES				= $(MAIN_FILES) $(S)game_entry.c $(S)init_player.c

CBONUS				= $(MAIN_FILES) $(B)init_player_bonus.c $(B)mouse_move_bonus.c $(B)game_entry_bonus.c
					  
 
					  



OBJ					= $(CFILES:.c=.o)
OBJB				= $(CBONUS:.c=.o)

LIB_EXT_MAKE 		= make $@ -C $(S)libft

.c.o:
	@ $(CC) $(OPTION) -c $< -o $@

$(NAME): $(OBJ)
	@ make -C $(S)libft
	@ $(CC) $(OPTION) $(OBJ) $(INCLUDES) $(S)libft/libft.a -o $(NAME)

$(BONUS): $(OBJB)
	@ make -C $(S)libft
	@ $(CC) $(OPTION) $(OBJB) $(INCLUDES) $(S)libft/libft.a -o $(BONUS)

all: $(NAME)

bonus: $(BONUS)

clean:
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(OBJ) $(OBJB)

fclean: clean
	@ $(LIB_EXT_MAKE)
	@ $(RM) $(NAME) $(BONUS) 

re: fclean all

run: all clean
	@ clear
	@ echo "MANDATORY"
	@ ./$(NAME) utils/map1.cub
	@ rm -rf .vscode
	@ make fclean

brun: bonus clean
	@ clear
	@ echo "BONUS"
	@ ./$(BONUS) utils/map1.cub
	@ rm -rf .vscode
	@ make fclean

.PHONY: re fclean all clean bonus brun run