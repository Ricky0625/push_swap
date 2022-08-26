/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:43:02 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/26 12:28:12 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
 * btm      : the index of the bottom item
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

// Args helper & Utils
int		*check_arguments(int ac, char **av, int *num);
char	*join_args(int ac, char **av);
int		get_num_of_args(char **args);
void	free_tabs(char **args);

// Stack operation
void	push(t_stack *stack, int item);
void	pop(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
int		peek(t_stack *stack);

// Instruction
void	s_instr(t_stkgrp *stacks, int instr);
void	p_instr(t_stkgrp *stacks, int instr);
void	r_instr(t_stkgrp *stacks, int instr, int print);
void	ft_swap(int *a, int *b);
void	swap_top(t_stack *stack, int instr);
void	push_top(t_stack *org, t_stack *dest, int instr);
void	push_n_item(t_stkgrp *stacks, int instr, int n);
void	rotate_stk(t_stack *stack, int instr, int print);
void	print_instr(int instr);

// Sorter
void	sort_stack(t_stkgrp *stacks, int num_of_arg);
void	sort_three(t_stkgrp *stacks, t_stack *main);
void	sort_small_stack(t_stkgrp *stacks, int num_of_arg);
void    quick_sort(t_stkgrp *stacks, int num_of_arg, int chunk);
int		check_if_sorted(t_stack *stack);

// Sorter utils
int		find_smallest(t_stack *stack);
int		find_largest(t_stack *stack);
void	give_way(t_stkgrp *stacks, int location, char stk);
void	restorer(t_stkgrp *stacks, char stk);
// int		*copy_items(int *items, int num_of_arg);

// Sorting algo
void	insertion_sort(t_stkgrp *stacks, char stk);
int		*bubble_sort(int *items, int size);

// Stack checker (for testing purpose only)
void	print_stack(t_stkgrp *stacks, int extra_info);
void    test_sort(t_stkgrp *stacks, int num_of_arg, int chunk);

#endif
