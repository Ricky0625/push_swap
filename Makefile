# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 11:23:49 by wricky-t          #+#    #+#              #
#    Updated: 2022/08/18 20:30:09 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

SRCS	:= srcs/push_swap.c \
		   srcs/args/args_helper.c \
		   srcs/args/args_utils.c \
		   srcs/stack/stack_operation.c \
		   srcs/stack/stack_helper.c \
		   srcs/instructions/swap.c \
		   srcs/instructions/push.c \
		   srcs/instructions/rotate.c \
		   srcs/instructions/instr_helper.c \
		   srcs/sorter/sort_stack.c \
		   srcs/sorter/sort_small.c

OBJS	:= $(SRCS:.c=.o)

INCLUDE	:= includes/push_swap.h

LIB		:= ./libft

CC		:= gcc

CFLAGS	?= -Wall -Werror -Wextra #-g3 -fsanitize=address

RM		:= rm -rf

all: $(NAME) libft
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

libft:
	@make all -C $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -L$(LIB) $(LIB)/*.a

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB)

re: fclean all
	@make re -C $(LIB)

.PHONY: clean fclean re libft push_swap

# styling
GR 	:= \033[1;92m
WH	:= \033[1;37m
YL	:= \033[0;33m
DF	:= \033[0m
