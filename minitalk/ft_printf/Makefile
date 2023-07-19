# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 11:34:43 by ohortal-          #+#    #+#              #
#    Updated: 2023/04/19 13:10:10 by ohortal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

OBJS =	$(SRCS:.c=.o)

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
INCLUDE = -I ft_printf.h
NAME = libftprintf.a
RM = rm -f

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
