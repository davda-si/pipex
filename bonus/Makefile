# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 13:52:10 by davda-si          #+#    #+#              #
#    Updated: 2024/01/03 16:17:36 by davda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = main.c process.c utils.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY:         all clean fclean re