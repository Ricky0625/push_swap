/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:05:17 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/20 19:06:56 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sort stack that has only three item, by comparing top, mid and btm item
**/
void sort_three(t_stkgrp *stacks, t_stack *main)
{
	int top;
	int mid;
	int btm;

	top = main->items[0];
	mid = main->items[1];
	btm = main->items[2];
	if (btm > mid && btm < top)
		r_instr(stacks, RA);
	else if (top > btm && top < mid)
		r_instr(stacks, RRA);
	else if (top > mid && top < btm)
		s_instr(stacks, SA);
	else if (top > mid && mid > btm)
	{
		s_instr(stacks, SA);
		r_instr(stacks, RRA);
	}
	else if (btm > top && mid > btm)
	{
		r_instr(stacks, RRA);
		s_instr(stacks, SA);
	}
}

/**
 * Sort stack with 4 to 5 elements
**/
void sort_small_stack(t_stkgrp *stacks, int num_of_arg)
{
	t_stack *a;
	t_stack *b;
	int	n;

	a = stacks->a;
	b = stacks->b;
	n = num_of_arg - 3;
	push_n_item(stacks, PB, n);
	sort_three(stacks, a);
	insertion_sort(b, a);
}

void	sort_big_stack(t_stkgrp *stacks)
{
	
}

/**
 * Sort the stack
 * 
 * 1. Check if the stack is sorted or not
 * 2. If not, and num_of_arg is 2, swap
 * 3. If not, and num_of_arg is 3, sort_three
 * 4. If not, and num_of_arg is between 4 and 5, sort_small_stack
 * 5. Else, sort using sort_big_stack
**/
void	sort_stack(t_stkgrp *stacks, int num_of_arg)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (check_if_sorted(a) == 1)
		exit(EXIT_SUCCESS);
	if (num_of_arg == 2)
		s_instr(stacks, SA);
	else if (num_of_arg == 3)
		sort_three(stacks, a);
	else if (num_of_arg <= 5)
		sort_small_stack(stacks, num_of_arg);
	else
		sort_big_stack(stacks);
}
