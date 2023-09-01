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

#SRCS_BONUS
SRC_BONUS_NAME =	main_bonus \
					utils_bonus \
					init/init_bonus \
					init/dfs_init_bonus \
					init/intarr_init_bonus \
					init/init_minimap_bonus \
					init/init_sprite_bonus \
					parse/map_bonus \
					parse/images_bonus \
					parse/input_file_bonus \
					parse/colors_bonus \
					parse/sprites_bonus \
					movement/handle_bonus \
					movement/movement_bonus \
					movement/rotate_bonus \
					movement/sprite_movement_bonus \
					render/render_bonus \
					render/raycast_bonus \
					render/texture_bonus \
					render/minimap_bonus \
					render/sprite_bonus \
					checks/map_checks_bonus \
					checks/dfs_bonus \
					checks/check_sprite_bonus
SRC_BONUS = $(SRC_BONUS_NAME:=.c)
SRCS_BONUS_PATH = ./srcs_bonus/
SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH), $(SRC_BONUS))

#OBJECTS
OBJECT = $(SRC:.c=.o)
OBJECTS_PATH = ./objects/
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECT))

#OBJECTS_BONUS
OBJECT_BONUS = $(SRC_BONUS:.c=.o)
OBJECTS_BONUS_PATH = ./objects_bonus/
OBJECTS_BONUS = $(addprefix $(OBJECTS_BONUS_PATH), $(OBJECT_BONUS))

#HEADERS
INCLUDE_PATH = ./includes

#HEADERS_BONUS
INCLUDE_BONUS_PATH = ./includes_bonus

NAME = cub3D

NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Wextra -Werror

all: $(OBJECTS_PATH) $(NAME)

bonus: $(OBJECTS_BONUS_PATH) $(NAME_BONUS)

$(OBJECTS_PATH):
	mkdir -p objects
	mkdir -p objects/init
	mkdir -p objects/movement
	mkdir -p objects/render
	mkdir -p objects/parse
	mkdir -p objects/checks

$(OBJECTS_BONUS_PATH):
	mkdir -p objects_bonus
	mkdir -p objects_bonus/init
	mkdir -p objects_bonus/movement
	mkdir -p objects_bonus/render
	mkdir -p objects_bonus/parse
	mkdir -p objects_bonus/checks

$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(CFLAGS) -I ./minilibx_opengl_20191021 -I ./libft -I $(INCLUDE_PATH) $< -o $@

$(OBJECTS_BONUS_PATH)%.o: $(SRCS_BONUS_PATH)%.c
	$(CC) -c $(CFLAGS) -I ./minilibx_opengl_20191021 -I ./libft -I $(INCLUDE_BONUS_PATH) $< -o $@

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc $(CFLAGS) $(OBJECTS) -o $(NAME) -L ./minilibx_opengl_20191021 -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

$(NAME_BONUS): $(OBJECTS_BONUS)
	make bonus -C ./libft
	cc $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS) -L ./minilibx_opengl_20191021 -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

clean:
	make clean -C ./libft
	rm -rf $(OBJECTS_PATH)
	rm -rf $(OBJECTS_BONUS_PATH)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
