# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 11:23:49 by wricky-t          #+#    #+#              #
#    Updated: 2022/08/29 17:02:50 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CHECKER	:= checker

SRCS	:= srcs/push_swap/push_swap.c \
		   srcs/push_swap/stack_operation.c \
		   srcs/push_swap/args/args_helper.c \
		   srcs/push_swap/args/args_utils.c \
		   srcs/push_swap/instructions/instr_helper.c \
		   srcs/push_swap/instructions/instr_utils.c \
		   srcs/push_swap/sorter/sort_stack.c \
		   srcs/push_swap/sorter/sort_utils.c \
		   srcs/push_swap/sorter/sort_algo.c \
		   srcs/push_swap/sorter/sort_big.c

B_SRCS	:= $(filter-out srcs/push_swap/push_swap.c,$(SRCS)) \
		   srcs/checker/checker.c \
		   srcs/checker/checker_utils.c \
		   get_next_line/get_next_line.c \
		   get_next_line/get_next_line_utils.c

OBJS	:= $(SRCS:.c=.o)

B_OBJS	:= $(B_SRCS:.c=.o)

INCLUDE	:= includes/push_swap.h

LIB		:= ./libft

CC		:= gcc

CFLAGS	?= -Wall -Werror -Wextra #-g3 -fsanitize=address

RM		:= rm -rf

all: $(NAME)
	@echo "  $(GR)╋╋╋╋$(YL)┏━┳┓┏━┓$(DF)"
	@echo "  $(YL)┏━┳┳┫━┫┗┫━╋┳┳┳━┓┏━┓$(DF)"
	@echo "  $(YL)┃╋┃┃┣━┃┃┣━┃┃┃┃╋┗┫╋┃$(DF)"
	@echo "  $(YL)┃┏┻━┻━┻┻┻━┻━━┻━━┫┏┛$(DF)"
	@echo "  $(YL)┗┛$(GR)╋╋╋╋╋╋╋╋╋╋╋╋╋╋$(YL)┗┛$(DF)"
	@echo ""
	@echo "$(YL)===== INSTRUCTION =====$(DF)"
	@echo "$(WH)./push_swap [numbers]$(DF)"
	@echo "$(YL)=======================$(DF)"

$(NAME): $(OBJS) $(INCLUDE)
	@echo "$(GR)↻ compiling...$(DF)"
	@echo ""
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIB) $(LIB)/*.a

bonus: $(CHECKER)
	@echo "$(YL)CHECKER CREATED!$(DF)"

$(CHECKER): $(B_OBJS) $(INCLUDE)
	@echo "$(GR)↻ compiling...$(DF)"
	@$(CC) $(CFLAGS) $(B_OBJS) -o $@ -L $(LIB) $(LIB)/*.a

libft:
	@make all -C $(LIB)

%.o: %.c libft
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@make clean -C $(LIB)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@make fclean -C $(LIB)

re: fclean all
	@make re -C $(LIB)

.PHONY: clean fclean re libft push_swap

# styling
GR 	:= \033[1;92m
WH	:= \033[1;37m
YL	:= \033[0;33m
DF	:= \033[0m
