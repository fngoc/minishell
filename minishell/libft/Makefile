# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 11:50:57 by fngoc             #+#    #+#              #
#    Updated: 2021/02/02 12:55:52 by fngoc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME = libft.a

HEADER = libft.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_strnew.c ft_strclr.c ft_strcpy.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAG = -Wall -Werror -Wextra

OPTION = -c

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ) $(OBJ_BONUS) $(HEADER)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) $(OPTION) $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
