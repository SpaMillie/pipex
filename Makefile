# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 17:30:47 by mspasic           #+#    #+#              #
#    Updated: 2024/04/27 13:45:51 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCE_FILES = main.c \
				error.c \
				pipex_strjoin.c \
				pipex_split.c \
				pipex.c 

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_PATH = Libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

##########################

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: clean fclean all re libft
