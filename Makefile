#SRCS
SRC_NAME =	main \
			utils \
			init/init \
			init/dfs_init \
			init/intarr_init \
			parse/map \
			parse/images \
			parse/input_file \
			parse/colors \
			movement/handle \
			movement/movement \
			movement/rotate \
			render/render \
			render/raycast \
			render/texture \
			checks/map_checks \
			checks/dfs 
SRC = $(SRC_NAME:=.c)
SRCS_PATH = ./srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRC))

#OBJECTS
OBJECT = $(SRC:.c=.o)
OBJECTS_PATH = ./objects/
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECT))

#HEADERS
INCLUDE_PATH = ./includes

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror 

all: $(OBJECTS_PATH) $(NAME)

$(OBJECTS_PATH):
	mkdir -p objects
	mkdir -p objects/init
	mkdir -p objects/movement
	mkdir -p objects/render
	mkdir -p objects/parse
	mkdir -p objects/checks

$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(CFLAGS) -I ./minilibx_opengl_20191021 -I ./libft -I $(INCLUDE_PATH) $< -o $@

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc $(CFLAGS) $(OBJECTS) -o $(NAME) -L ./minilibx_opengl_20191021 -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

clean:
	make clean -C ./libft
	rm -rf $(OBJECTS_PATH)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
