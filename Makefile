# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouinia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 12:30:34 by asouinia          #+#    #+#              #
#    Updated: 2021/11/03 13:01:56 by asouinia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
SRC			:= ft_printf.c
OBJ			:= $(SRC:.c=.o)
FLAGS		:= -Wall -Wextra -Werror
.PHONY		:  all clean fclean re libft

all: $(NAME)

$(NAME):  $(OBJ)

%.o:%.c
	gcc $(FLAGS) -c $< -I.
	ar -rc $(NAME) $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus:

tests: $(NAME)
	gcc $(FLAGS) main.c $(NAME) -o t -I.
	./t