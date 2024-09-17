EXECUTABLE := cub3D
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./includes
BT_DIR = ./builtins

INCLUDES = ./includes/minilibx.h ./includes/libraries.h ./includes/funtcions.h ./includes/inp_data.h ./includes/exec.h

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)  $(wildcard $(SRC_DIR)/*/*/*.c) $(wildcard $(SRC_DIR)/*/*/*/*.c)
#SRCS =	./src/main.c


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