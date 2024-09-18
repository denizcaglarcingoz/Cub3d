EXECUTABLE := cub3D
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./includes
BT_DIR = ./builtins

INCLUDES = ./includes/libraries.h ./includes/minilibx.h ./includes/funtcions.h ./includes/inp_data.h ./includes/exec.h

#SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)  $(wildcard $(SRC_DIR)/*/*/*.c) $(wildcard $(SRC_DIR)/*/*/*/*.c)
SRCS =	./src/main.c \
		\
		./src/errors/arg_error.c \
		./src/errors/clean_exit.c \
		./src/errors/element_check_err.c \
		./src/errors/fd_error.c \
		./src/errors/malloc_error.c \
		\
		./src/execution/mlx_actions/key_hook.c \
		./src/execution/draw_wall.c \
		./src/execution/exec_main.c \
		./src/execution/move.c \
		./src/execution/texture.c \
		./src/execution/textures_util.c \
		\
		./src/free/inp_data_free.c \
		\
		./src/inp_check/color_set.c \
		./src/inp_check/data_check.c \
		./src/inp_check/file_name_check.c \
		./src/inp_check/get_file_data.c \
		./src/inp_check/inp_check_main.c \
		./src/inp_check/inp_to_null.c \
		./src/inp_check/set_p_pos.c \
		./src/inp_check/map/map_check_main.c \
		./src/inp_check/map/map_data_copy.c \
		./src/inp_check/map/map_init.c \
		./src/inp_check/map/map_into_array.c \
		./src/inp_check/map/map_wall_checks/char_check.c \
		./src/inp_check/map/map_wall_checks/map_border_hor.c \
		./src/inp_check/map/map_wall_checks/map_border_ver.c \
		./src/inp_check/map/map_wall_checks/map_wall_check.c \
		./src/inp_check/map/map_wall_checks/wall_hor_check.c \
		./src/inp_check/map/map_wall_checks/wall_ver_check.c \
		./src/inp_check/elements/color_check.c \
		./src/inp_check/elements/color_comma_check.c \
		./src/inp_check/elements/color_num_check.c \
		./src/inp_check/elements/does_file_exist.c \
		./src/inp_check/elements/element_check.c \
		./src/inp_check/elements/is_color.c \
		./src/inp_check/elements/is_element.c \
		./src/inp_check/elements/is_xpm.c \
		./src/inp_check/elements/path_check.c \
		\
		./src/tests/print_d_str.c 


OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS := -Wall -Wextra -Werror -Iincludes -I/usr/local/lib

#LDFLAGS := -L/usr/local/lib -lmlx -lXext -lX11 -lreadline -lhistory
LDFLAGS := -Llib -lmlx -lXext -lX11 -lreadline -lhistory -lm

RM := rm -f

LIBFT_PATH = includes/libft

LIBFT_ARCH = $(LIBFT_PATH)/libft.a

CC := cc

OBS := $(SRCS:.c=.o)

MAKEFLAGS += --no-print-directory


all: $(LIBFT_ARCH) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $^ -L$(LIBFT_PATH) -lft -lreadline -lhistory $(LDFLAGS) -o $@ 

$(LIBFT_ARCH):
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(EXECUTABLE)

re: fclean all



.PHONY: all clean fclean re