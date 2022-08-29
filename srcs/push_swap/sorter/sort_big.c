/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:36:01 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 15:21:51 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * Push chunk (partition) to stack b
 * This is a recursive function. The base case is when stack a has less than
 * or equal 3 item left OR stack a is sorted.
 *
 * 1. Create a copy of the items.
 * 2. Bubble sort the copy (whatever sorting algo will do but i think bubble
 *    sort is the easiest to implement)
 * 3. Get the pivot of the sorted copy. This is to make sure that when
 *    doing partitioning, we can gurantee that the partition size is balance.
 * 4. Everytime we will push the half of stack a to stack b, so in every turn,
 *    stack_b will be (previous stack_b size + stack_a size / 2). When stack b
 *    size is less than that, keep push item from stack a that are less than
 *    pivot. If it's greater than pivot, RA.
 * 5. OPTIMIZATION. If the pushed item is less than the "median of pivot",
 *    rotate it down, RB. This is to reduce the rotations when we need to push
 *    back the items to stack a afterward.
 * 6. Update num_of_arg, and chunk size before calling itself.
 * 7. Call itself again.
 **/
static void push_chunk(t_stkgrp *stacks, int num_of_arg, int chunk, int cutsize)
{
	t_stack *a;
	t_stack *b;
	int *copy;
	int pivot;

	a = stacks->a;
	b = stacks->b;
	if (a->btm + 1 <= 3 || check_if_sorted(a) == 1)
		return;
	copy = bubble_sort(a->items, num_of_arg);
	pivot = num_of_arg / cutsize;
	while (b->btm + 1 < chunk)
	{
		if (peek(a) < copy[pivot])
		{
			p_instr(stacks, PB);
			if (peek(b) < copy[pivot / 2])
				r_instr(stacks, RB, 1);
		}
		else
			r_instr(stacks, RA, 1);
	}
	num_of_arg -= (num_of_arg / cutsize);
	chunk += (num_of_arg / cutsize);
	push_chunk(stacks, num_of_arg, chunk, cutsize);
}

/**
 * Quicksort (push swap way)
 *
 * 1. Push chunk. Everytime push half of stack a to stack b until base case
 *    is reached.
 * 2. Check if stack a is sorted, if no, sort it.
 * 3. Push back item from stack b to stack a.
 * 	   i.	Find largest item
 *     ii.	Move largest item to the top using smart rotate
 *     iii.	Push the largest item to the stack a
 **/
void quick_sort(t_stkgrp *stacks, int num_of_arg, int cutsize)
{
	t_stack *a;
	t_stack *b;
	int loc;

	a = stacks->a;
	b = stacks->b;
	push_chunk(stacks, num_of_arg, num_of_arg / cutsize, cutsize);
	if (check_if_sorted(a) == 0)
		sort_stack(stacks, a->btm + 1);
	while (is_empty(b) != 1)
	{
		loc = find_largest(b);
		give_way(stacks, loc, 'B');
		p_instr(stacks, PA);
	}
}
