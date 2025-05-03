# **************************************************************************** #
#	                                                                          #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 03:00:27 by hirwatan          #+#    #+#              #
#    Updated: 2025/04/30 03:12:25 by hirwatan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
MLX_DIR = minilibx-linux

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJ_DIRS = $(sort $(dir $(OBJS)))

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(OBJ_DIRS):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

v: all
	valgrind --leak-check=full ./cub3D ./map/test.cub

.PHONY: all clean fclean re v