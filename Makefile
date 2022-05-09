# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 00:06:36 by nnakarac          #+#    #+#              #
#    Updated: 2022/05/09 15:27:44 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
OBJD_DIR = objds/
LIB_DIR = libft/

INCS = -Iincludes/ -I$(LIB_DIR)includes/
NAME = push_swap
NAMED = push_swap_debug
SRCS = push_swap.c \
	push_swap_stack_cmd1.c \
	push_swap_stack_cmd2.c \
	push_swap_stack_utils1.c \
	push_swap_stack_utils2.c \
	push_swap_stack_utils3.c \
	push_swap_stack_prints.c \
	push_swap_input_sort_chk.c \
	push_swap_input_sort_chk2.c \
	push_swap_input_verify.c \
	push_swap_err_msg.c

OBJS = $(SRCS:.c=.o)
RNDS100 = `ruby -e "puts (0..100).to_a.shuffle.join(' ')";`
RNDS500 = `ruby -e "puts (0..500).to_a.shuffle.join(' ')";`

all: $(NAME)

debug: $(NAMED)

$(NAME):	$(addprefix $(OBJ_DIR),$(OBJS))
		@make -C $(LIB_DIR) --silent
		$(CC) $(addprefix $(OBJ_DIR),$(OBJS)) -o push_swap -L $(LIB_DIR) -lft

$(NAMED):	$(addprefix $(OBJD_DIR),$(OBJS))
		@make -C $(LIB_DIR) --silent
		$(CC) -g $(addprefix $(OBJD_DIR),$(OBJS)) -o push_swap_debug -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@

$(OBJD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJD_DIR)
	$(CC) -g $(CFLAGS) -c $< $(INCS) -o $@

bonus: $(NAME)

clean:
	@make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJD_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	$(RM) push_swap
	$(RM) push_swap_debug

re: fclean all

test100: re
	@./push_swap $(RNDS100)

testv100:
	@valgrind --leak-check=full ./push_swap $(RNDS100)

test500: re
	@./push_swap $(RNDS500)

testv500:
	@valgrind --leak-check=full ./push_swap $(RNDS500)

norm_c:
	@norminette -R CheckForbiddenSourceHeader **/*.c

norm_h:
	@norminette -R CheckDefine **/*.h

norm_a:	norm_c norm_h

.PHONY: all clean fclean re push_swap norm_c norm_h norm_a test100 test500 testv100 testv500
