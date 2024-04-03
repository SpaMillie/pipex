# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 17:30:47 by mspasic           #+#    #+#              #
#    Updated: 2024/04/03 17:40:05 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCE_FILES = pipex.c
OBJECT_FILES = $(SOURCE_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

##########################

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re pipex
