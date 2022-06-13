# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 00:06:36 by nnakarac          #+#    #+#              #
#    Updated: 2022/06/12 10:46:27 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
OBJC_DIR = objcs/
OBJD_DIR = objds/
LIB_DIR = libft/

INCS = -Iincludes/ -I$(LIB_DIR)includes/
NAME = push_swap
NAMED = push_swap_debug
NAMEC = checker

SRCS = push_swap.c \
	push_swap_stack_cmd1.c \
	push_swap_stack_cmd2.c \
	push_swap_stack_cmd3.c \
	push_swap_stack_cmd4.c \
	push_swap_stack_cmd5.c \
	push_swap_stack_cmd6.c \
	push_swap_stack_cmd7.c \
	push_swap_stack_utils1.c \
	push_swap_stack_utils2.c \
	push_swap_stack_utils3.c \
	push_swap_stack_prints.c \
	push_swap_stack_tester.c \
	push_swap_sort_opr1.c \
	push_swap_sort_opr2.c \
	push_swap_sort_opr3.c \
	push_swap_sort_opr4.c \
	push_swap_sort_opr5.c \
	push_swap_sort_opr6.c \
	push_swap_input_sort_chk.c \
	push_swap_input_sort_chk2.c \
	push_swap_input_sort_chk3.c \
	push_swap_input_verify.c \
	push_swap_err_msg.c

CKRS = checker.c \
	push_swap_stack_cmd1.c \
	push_swap_stack_cmd2.c \
	push_swap_stack_cmd3.c \
	push_swap_stack_cmd4.c \
	push_swap_stack_cmd5.c \
	push_swap_stack_cmd6.c \
	push_swap_stack_cmd7.c \
	push_swap_stack_utils1.c \
	push_swap_stack_utils2.c \
	push_swap_stack_utils3.c \
	push_swap_stack_prints.c \
	push_swap_stack_tester.c \
	push_swap_input_sort_chk.c \
	push_swap_input_sort_chk2.c \
	push_swap_input_sort_chk3.c \
	push_swap_input_verify.c \
	push_swap_err_msg.c

OBJS = $(SRCS:.c=.o)
OBJC = $(CKRS:.c=.o)

RNDS5 = `ruby -e "puts (1..5).to_a.shuffle.join(' ')";`
RNDS10 = `ruby -e "puts (1..10).to_a.shuffle.join(' ')";`
RNDS100 = `ruby -e "puts (1..100).to_a.shuffle.join(' ')";`
RNDS500 = `ruby -e "puts (1..500).to_a.shuffle.join(' ')";`

RNDSN5 = `ruby -e "puts (-2..2).to_a.shuffle.join(' ')";`
RNDSN10 = `ruby -e "puts (-5..4).to_a.shuffle.join(' ')";`
RNDSN100 = `ruby -e "puts (-50..49).to_a.shuffle.join(' ')";`
RNDSN500 = `ruby -e "puts (-250..249).to_a.shuffle.join(' ')";`

all: $(NAME) $(NAMEC)

check: $(NAMEC)

debug: $(NAMED)

$(NAME):	$(addprefix $(OBJ_DIR),$(OBJS))
		@make -C $(LIB_DIR) --silent
		@$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJS)) -o push_swap -L $(LIB_DIR) -lft

$(NAMEC):	$(addprefix $(OBJC_DIR),$(OBJC))
		@make -C $(LIB_DIR) --silent
		@$(CC) $(CFLAGS) $(addprefix $(OBJC_DIR),$(OBJC)) -o checker -L $(LIB_DIR) -lft

$(NAMED):	$(addprefix $(OBJD_DIR),$(OBJS))
		@make -C $(LIB_DIR) --silent
		@$(CC) -g $(CFLAGS) $(addprefix $(OBJD_DIR),$(OBJS)) -o push_swap_debug -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< $(INCS) -o $@

$(OBJD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJD_DIR)
	@$(CC) -g $(CFLAGS) -c $< $(INCS) -o $@

$(OBJC_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJC_DIR)
	@$(CC) -g $(CFLAGS) -c $< $(INCS) -o $@

bonus: $(NAME)

clean:
	@make -C $(LIB_DIR) clean --silent
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJC_DIR)
	@$(RM) $(OBJD_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@$(RM) push_swap
	@$(RM) checker
	@$(RM) push_swap_debug

re: fclean all

red: fclean debug

test5: re
	@./push_swap $(RNDS5)

testv5:
	@valgrind --leak-check=full ./push_swap $(RNDS5)

test10: re
	@./push_swap $(RNDS10)

testv10:
	@valgrind --leak-check=full ./push_swap $(RNDS10)

test100: re
	@./push_swap $(RNDS100)

test100b:
	@./push_swap $(RNDS100)

test100d: red
	@lldb ./push_swap_debug $(RNDS100)

testv100:
	@valgrind --leak-check=full ./push_swap $(RNDS100)

test500: re
	@./push_swap $(RNDS500)

test500b:
	@./push_swap $(RNDS500)

testv500:
	@valgrind --leak-check=full ./push_swap $(RNDS500)

testn5: re
	@./push_swap $(RNDSN5)

testnv5:
	@valgrind --leak-check=full ./push_swap $(RNDSN5)

testn10: re
	@./push_swap $(RNDSN10)

testnv10:
	@valgrind --leak-check=full ./push_swap $(RNDSN10)

testn100: re
	@./push_swap $(RNDSN100)

testnv100:
	@valgrind --leak-check=full ./push_swap $(RNDSN100)

testn500: re
	@./push_swap $(RNDSN500)

testnv500:
	@valgrind --leak-check=full ./push_swap $(RNDSN500)

norm_c:
	@norminette -R CheckForbiddenSourceHeader **/*.c

norm_h:
	@norminette -R CheckDefine **/*.h

norm_a:	norm_c norm_h

.PHONY: all clean fclean re push_swap norm_c norm_h norm_a test100 test500 testv100 testv500 checker check
