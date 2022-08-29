/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:05:17 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 15:21:51 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * Check if a stack is sorted
 *
 * Ideally, if the stack is sorted, the topmost item will be the smallest;
 * largest at the bottom. So, iterate through from the top, compare the
 * current item with the item below it. If the current item is greater than
 * the next item, meaning it's not sorted, return 0 to the caller. If we
 * manage compare to the last item, meaning it's sorted, return 1 to the caller.
 *
 * Notice that we only compare until i less than stack->capacity - 1, meaning
 * until the max index. This is to avoid the function to overlook.
 **/
int check_if_sorted(t_stack *stack)
{
	int i;
	int *items;

	i = -1;
	items = stack->items;
	if (is_empty(stack) == 1)
		return (0);
	while (++i < stack->btm)
	{
		if (items[i] > items[i + 1])
			return (0);
	}
	return (1);
}

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
		r_instr(stacks, RA, 1);
	else if (top > btm && top < mid)
		r_instr(stacks, RRA, 1);
	else if (top > mid && top < btm)
		s_instr(stacks, SA);
	else if (top > mid && mid > btm)
	{
		s_instr(stacks, SA);
		r_instr(stacks, RRA, 1);
	}
	else if (btm > top && mid > btm)
	{
		r_instr(stacks, RRA, 1);
		s_instr(stacks, SA);
	}
}

/**
 * Sort stack with 4 to 5 elements
 *
 * First push n items from stack a to stack b so that stack a will
 * only left 3 items. Sort stack a using sort_three and use insertion
 * sort to sort stack b and push it back to stack a at the same time.
 **/
void sort_small_stack(t_stkgrp *stacks, int num_of_arg)
{
	t_stack *a;
	t_stack *b;
	int n;

	a = stacks->a;
	b = stacks->b;
	n = num_of_arg - 3;
	push_n_item(stacks, PB, n);
	sort_three(stacks, a);
	insertion_sort(stacks, 'A');
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
void sort_stack(t_stkgrp *stacks, int num_of_arg)
{
	t_stack *a;
	t_stack *b;

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
	else if (num_of_arg <= 100)
		quick_sort(stacks, num_of_arg, 2);
	else if (num_of_arg <= 500)
		quick_sort(stacks, num_of_arg, 4);
}
