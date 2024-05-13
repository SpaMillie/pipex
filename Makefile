# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 17:30:47 by mspasic           #+#    #+#              #
#    Updated: 2024/05/13 20:22:32 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus

SOURCE_FILES = main.c \
				error.c \
				pipex_strjoin.c \
				pipex_split.c \
				pipex_substr.c \
				pipex.c \
				open_and_parse.c \
				utils.c

BONUS_FILES = $(SOURCE_FILES:main.c=main_bonus.c)

OBJECT_FILES = $(SOURCE_FILES:.c=.o)
OBJ_BON_FLS = $(BONUS_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = Libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

##########################

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BON_FLS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BON_FLS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	rm -f $(OBJ_BON_FLS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: clean fclean all bonus re libft
