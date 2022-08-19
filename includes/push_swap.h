/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:43:02 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 21:15:30 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

// Macros
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 13
# define RRA 8
# define RRB 9
# define RRR 17

/**
 * STACK
 * Implement using Dynamic Array
 * 
 * capacity : the max capacity of the stack
 * top      : the index of the top item
 * item     : dynamic array
**/
typedef struct s_stack
{
	int	capacity;
	int	btm;
	int	*items;
}	t_stack;

/**
 * STACK GROUP
 * 
 * Group of stack
 * a	: stack a
 * b	: stack b
**/
typedef struct s_stkgrp
{
	t_stack	*a;
	t_stack	*b;
}	t_stkgrp;

// Args helper
int		*check_arguments(int ac, char **av, int *num);

// Args Utils
char	*join_args(int ac, char **av);
int		get_num_of_args(char **args);
void	free_tabs(char **args);

// Stack operation
void	push(t_stack *stack, int item);
void	pop(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
int		peek(t_stack *stack);

// Stack helper
int		init_stack(t_stack *stack, int num_of_arg);
void	push_args(t_stack *stack, int *args);
void	print_instr(int instr);
int		check_if_sorted(t_stack *stack);

// Instruction
void	s_instr(t_stkgrp *stacks, int instr);
void	p_instr(t_stkgrp *stacks, int instr);
void	r_instr(t_stkgrp *stacks, int instr);

// Instruction helper
void	ft_swap(int *a, int *b);
void	push_all(t_stkgrp *stacks, int instr);
void	push_n_item(t_stkgrp *stacks, int instr, int n);

// Sorter
void	sort_stack(t_stkgrp *stacks, int num_of_arg);
void	sort_three(t_stkgrp *stacks, t_stack *main);

// Sorter utils
int	binary_search(t_stack *stack, int target, int low, int high);

// Stack checker (for testing purpose only)
void	print_stack(t_stkgrp *stacks, int extra_info);

#endif
