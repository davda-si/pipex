# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:59:28 by davda-si          #+#    #+#              #
#    Updated: 2024/01/03 16:16:32 by davda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
ft_args.c ft_hex.c ft_point.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
get_next_line_utils_bonus.c get_next_line.c \
get_next_line_utils.c get_next_line_bonus.c

OBJ = ${SRC:.c=.o}

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_B = ${SRC_B:.c=.o}

CC = @cc

CCFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
		@ar -crs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	@ar -crs $(NAME) $(OBJ) $(OBJ_B)

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:		clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
	 