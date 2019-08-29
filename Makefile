# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 13:30:17 by ssheba            #+#    #+#              #
#    Updated: 2019/08/29 17:16:08 by ssheba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

RDG_DIR		=	./src/reading
CONE_DIR	=	./src/cone
CLND_DIR	=	./src/cylinder
MAT_DIR		=	./src/mat
PLN_DIR		=	./src/plane
SPH_DIR		=	./src/sphere
WIN_DIR		=	./src/win
OBJ_DIR		=	./obj
INC_DIR		=	./includes

RDG_FILES	=	get_double.c get_fd.c get_person.c reading.c reading_shine.c \
				reading_utils.c get_cone.c get_cylinder.c get_plane.c \
				get_sphere.c
CONE_FILES	=	cone_intersection.c create_cone.c get_cone_color.c
CLND_FILES	=	create_cylinder.c cylinder_intersection.c get_cylinder_color.c
MAT_FILES	=	mat3.c mat3_op.c mat3_rot.c vec3.c vec3_op.c
PLN_FILES	=	create_plane.c get_plane_color.c plane_intersection.c
SPH_FILES	=	create_sphere.c get_sphere_color.c sphere_intersection.c
WIN_FILES	=	create_person.c event.c finish.c get_lighting.c init_objects.c main.c set_pixel.c start.c trace.c
OBJ_FILES	=	$(RDG_FILES:.c=.o) $(CONE_FILES:.c=.o) $(CLND_FILES:.c=.o) $(MAT_FILES:.c=.o) $(PLN_FILES:.c=.o) $(SPH_FILES:.c=.o) $(WIN_FILES:.c=.o)
INC_FILES	=	geometry.h mat.h reading.h

RDG			=	$(addprefix $(RDG_DIR)/, $(RDG_FILES))
CONE		=	$(addprefix $(CONE_DIR)/, $(CONE_FILES))
CLND		=	$(addprefix $(CLND_DIR)/, $(CLND_FILES))
MAT			=	$(addprefix $(MAT_DIR)/, $(MAT_FILES))
PLN			=	$(addprefix $(PLN_DIR)/, $(PLN_FILES))
SPH			=	$(addprefix $(SPH_DIR)/, $(SPH_FILES))
WIN			=	$(addprefix $(WIN_DIR)/, $(WIN_FILES))
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

$(OBJ_DIR)/%.o: $(RDG_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(CONE_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(CLND_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(MAT_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(PLN_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SPH_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(WIN_DIR)/%.c $(INC)
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