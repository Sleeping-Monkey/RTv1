# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 13:30:17 by ssheba            #+#    #+#              #
#    Updated: 2019/07/25 10:51:19 by ssheba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./includes

SRC_FILES	=	add_vec.c get_sphere_color.c scalar_prod.c sub_vec.c \
				create_sphere.c init_objects.c set_pixel.c trace.c event.c \
				main.c sphere_intersection.c finish.c mul_vec_real.c start.c
OBJ_FILES	=	$(SRC_FILES:.c=.o)
INC_FILES	=	my_sdl.h

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))

INCLUDES	=	-I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers -I $(INC_DIR)
FLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -F ~/Library/Frameworks/ -framework SDL2

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -f $(NAME)

re: fclean all