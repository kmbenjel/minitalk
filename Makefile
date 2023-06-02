# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 10:23:49 by kbenjell          #+#    #+#              #
#    Updated: 2023/06/02 10:23:57 by kbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SSRC = server.c
CSRC = client.c

SSRC_B = server_bonus.c 
CSRC_B = client_bonus.c

LIBFT = libft.a

NAME = minitalk
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SSRC) $(CSRC)
	@	make -C libft/
	@	$(CC) $(CFLAGS) $(SSRC) $(LIBFT) -o server
	@	$(CC) $(CFLAGS) $(CSRC) $(LIBFT) -o client
	@	echo "\033[32m make: OK \033[0m"

clean:
	@	$(RM) $(OBJ)
	@	echo "\033[32m clean: OK \033[0m"

fclean: clean
	@	$(RM) $(NAME)
	@	echo "\033[32m fclean: OK \033[0m"

re: fclean all

.PHONY: clean fclean re all
