# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 00:06:36 by nnakarac          #+#    #+#              #
#    Updated: 2022/05/01 15:58:49 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

INCS = -Iincludes/ -I$(LIB_DIR)includes/
NAME = push_swap
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
RNDS100 = `ruby -e "puts (0..100).to_a.shuffle.join(' ')";`
RNDS500 = `ruby -e "puts (0..500).to_a.shuffle.join(' ')";`

all: $(NAME)

$(NAME):	$(addprefix $(OBJ_DIR),$(OBJS))
		@make -C $(LIB_DIR) --silent
		$(CC) $(addprefix $(OBJ_DIR),push_swap.o) -o push_swap -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@

bonus: $(NAME)

clean:
	@make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	$(RM) push_swap

re: fclean all

test100:
	./push_swap $(RNDS100)

test500:
	./push_swap $(RNDS500)

.PHONY: all clean fclean re push_swap
