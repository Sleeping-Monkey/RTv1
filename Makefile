# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 13:30:17 by ssheba            #+#    #+#              #
#    Updated: 2019/08/13 16:04:21 by ssheba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./includes

SRC_FILES	=	get_sphere_color.c create_sphere.c init_objects.c set_pixel.c \
				trace.c event.c main.c sphere_intersection.c finish.c start.c \
				get_lighting.c init_shine.c create_plane.c get_plane_color.c \
				plane_intersection.c create_cylinder.c cylinder_intersection.c \
				get_cylinder_color.c mat4.c mat4_op.c vec3_op.c vec3.c \
				create_person.c create_cone.c cone_intersection.c get_cone_color.c
OBJ_FILES	=	$(SRC_FILES:.c=.o)
INC_FILES	=	my_sdl.h geometry.h mat.h

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
FRAMEWORK	=	~/Library/Frameworks/SDL2.framework

OS			:=	$(shell uname -s)

ifeq ($(OS), Linux)
	INCLUDES	=	-I $(INC_DIR) -I $(LIBFT_DIR)
	LINK		=	-lpthread -lSDL2 -lm
else
	INCLUDES	=	-I ./Frameworks/SDL2.framework/Versions/A/Headers -I $(INC_DIR) -I $(LIBFT_DIR)
	LINK		=	-F ./Frameworks/ -framework SDL2 -lpthread
endif
FLAGS		=	-Wall -Wextra -Werror $(INCLUDES) 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LINK)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(LIBFT): FAKE
	$(MAKE) -C $(LIBFT_DIR)

$(FRAMEWORK):
	cp -r ./Frameworks ~/Library/

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: FAKE