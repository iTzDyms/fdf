#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2014/02/21 16:56:56 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -03
RM = @rm -rf

LIBFT_DIR = ./libft

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = fdf

OBJ_DIR = obj
SRC_DIR = srcs

SRC = 	main.c \
		ft_bresenham.c \
		ft_create_lst.c \
		ft_dlstnew.c \
		ft_print_dlst.c \

OBJ = $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_DIR)/, $(OBJ))

MLX_DIR = /usr/X11/lib
MLX_LIB = -lmlx -lXext -lX11

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "\nCompilation of objects for "$(LIBFT)
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(POBJ) $(LIBFT)
	@echo "\nLinking "$(NAME)""
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $^ \
	-L$(LIBFT_DIR) -lft -lft -L$(MLX_DIR) $(MLX_LIB) \
	-I$(INCLUDES_DIR)
	@echo "\n\x1b[32;01mdone!\x1b[0m"

clean:
	@echo "\nCleaning OBJ"
	$(RM) $(POBJ)

fclean: clean
	@echo "\nCleaning "$(NAME)""
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean
