# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 13:18:32 by ohortal-          #+#    #+#              #
#    Updated: 2023/07/19 14:27:38 by ohortal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Minitalk.a

SRCS= server.c client.c

SRCS_B= server_bonus.c client_bonus.c

OBJ= $(SRCS:.c=.o)

OBJ_B= $(SRCS_B:.c=.o)

$(NAME): $(OBJ)
	make -sC ./ft_printf
	gcc -Wall -Werror -Wextra  ./ft_printf/libftprintf.a server.c -o server
	gcc -Wall -Werror -Wextra  ./ft_printf/libftprintf.a client.c -o client

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(NAME) $(OBJ) $(OBJ_B) a.out server client server_bonus client_bonus
	@make -sC ./ft_printf/ fclean

fclean: clean
		@rm -rf ft_printf.a Minitalk.a

bonus: $(NAME) $(OBJ_B)
	make bonus -sC ./ft_printf
	gcc -Wall -Werror -Wextra -fsanitize=address ./ft_printf/libftprintf.a server_bonus.c -o server_bonus
	gcc -Wall -Werror -Wextra -fsanitize=address ./ft_printf/libftprintf.a client_bonus.c -o client_bonus

.PHONY: all clean re fclean bonus
