# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 21:47:50 by tpoungla          #+#    #+#              #
#    Updated: 2023/09/23 11:35:55 by tpoungla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g -pthread
//CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=address

CC = gcc

SRC = philosophers.c init.c pthread.c time.c \
util/tools1.c util/tools2.c util/tools3.c util/tools4.c

OBJ	:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "complied done!"

norm:
	norminette -R checkforbiddensourceheader $(SRC)
	norminette -R checkdefine philo.h
clean:
	@rm -f $(OBJ)
	@echo "yep, cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "tidy -- totally cleaned!"

re: fclean all

.PHONY: clean fclean all re norm