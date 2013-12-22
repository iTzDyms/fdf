#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2013/12/22 17:34:05 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

export CC = gcc
export CFLAGS = -Wall -Werror -Wextra
export OFLAGS = -O3
export RM = rm -rf

LIBFT_DIR = ./libft
MLX_DIR = /usr/X11/lib
MLX_LIB = -lmlx -lXext -lX11

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = fdf


SRC = 	main.c \
		ft_create_lst.c \
		ft_dlstnew.c \
		ft_print_dlst.c \
		ft_bresenham.c \

OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(NAME)

$(LIBFT):
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_LIB) -I$(INCLUDES_DIR)

clean:
	@($(MAKE) $@ -C $(LIBFT_DIR))
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

%.o: %.c $(INCLUDES_DIR)
	$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

.PHONY: all clean re fclean
