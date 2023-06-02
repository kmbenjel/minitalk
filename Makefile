# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 10:23:49 by kbenjell          #+#    #+#              #
#    Updated: 2023/06/02 20:31:36 by kbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SSRC = server.c
CSRC = client.c

SERVER = server
CLIENT = client

SSRC_B = server_bonus.c 
CSRC_B = client_bonus.c

LIBFT = libft/libft.a

NAME = $(SERVER) $(CLIENT)

RM = rm -f

all: $(NAME)

$(NAME): $(SSRC) $(CSRC)
	@	make -C libft/
	@	$(CC) $(CFLAGS) $(SSRC) $(LIBFT) -o $(SERVER)
	@	$(CC) $(CFLAGS) $(CSRC) $(LIBFT) -o $(CLIENT)
	@	echo "\033[32m make: OK \033[0m"

clean:
	@	make clean -C libft/ 
	@	echo "\033[32m clean: OK \033[0m"

fclean: clean
	@	$(RM) $(SERVER) $(CLIENT) $(LIBFT)
	@	echo "\033[32m fclean: OK \033[0m"

re: fclean all

.PHONY: clean fclean re all
