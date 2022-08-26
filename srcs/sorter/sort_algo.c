/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:04:19 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/26 18:12:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Binary search
 * 
 * Time complexity
 * Best     : O(1)
 * Average  : O(log n)
 * Worst    : O(log n)
 * Notes: `log` here refers to `log in base 2`
 * 
 * Works only when the list is in sorted order.
 * For example, names in a phone book are sorted in alphabetical order.
 * ========================================================================
 * binary_search function takes a sorted array, an item (target), and the
 * minimum(top) and maximum(btm) index to look at.
 * mid  : the midpoint between top and btm index
 * items: the items array
 * If the btm is <= top, like so: "top: 0, btm: 0" check if the target is
 * greater than the item, if yes, return top + 1, else return top.
 * If btm is >= top, like so: "top: 0, btm: 5", get midpoint.
 * If target is equal to the item at midpoint (actually will not happen),
 * return mid + 1 (for the sake of algo stability)
 * If the target is greater than the item at mid, do binary_search, but
 * this time, start searching from mid +1 to the btm.
 * Else, do binary_search from top to mid -1. (meaning target is smaller
 * than the item at midpoint)
**/
static int	binary_search(t_stack *dest, int target, int top, int btm)
{
	int	mid;
	int	*items;

	items = dest->items;
	if (btm <= top)
	{
		if (target > items[top])
			return (top + 1);
		return (top);
	}
	mid = (top + btm) / 2;
	if (target == items[mid])
		return (mid + 1);
	if (target > items[mid])
		return (binary_search(dest, target, mid + 1, btm));
	return (binary_search(dest, target, top, mid - 1));
}

/**
 * Insertion sort (the push_swap way)
 * 
 * Find the most suitable place in dest stack to place the top of origin stack
 * 
 * 1. Iterate when the origin stack is not empty
 * 2. Peek the top value of origin stack
 * 3. Binary search through the destination stack, to see where to place the
 * 	  top item of origin stack
 * 4. Destination stack need to give way for the top item of origin stack
 * 5. Push the top value of origin to destination
 * 6. OPTIMIZATION := If the following item on origin stack is greater than
 *    the newly pushed item, and it's less than the item at btm, continue to
 *    push
 * 7. Run restorer. Let the smallest item to be at the top again.
**/
void	insertion_sort(t_stkgrp *stacks, char dest_stk)
{
	t_stack	*org;
	t_stack	*dest;
	int		top_org;
	int		loc;

	org = stacks->a;
	dest = stacks->b;
	if (dest_stk == 'A')
	{
		org = stacks->b;
		dest = stacks->a;
	}
	while (is_empty(org) != 1)
	{
		top_org = peek(org);
		loc = binary_search(dest, top_org, 0, dest->btm);
		give_way(stacks, loc, dest_stk);
		push_top(org, dest, PA);
		while (peek(dest) > peek(org) && peek(org) > dest->items[dest->btm])
			push_top(org, dest, PA);
		restorer(stacks, dest_stk);
	}
}

/**
 * Create a copy of items
**/
static int	*copy_items(int *items, int num_of_arg)
{
	int	i;
	int	*copy;

	i = -1;
	copy = malloc(sizeof(int) * num_of_arg);
	while (++i < num_of_arg)
		copy[i] = items[i];
	return (copy);
}

/**
 * Create a copy and Bubble sort
**/
int	*bubble_sort(int *items, int size)
{
	int	i;
	int	j;
	int	*copy;

	i = -1;
	copy = copy_items(items, size);
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (copy[j] > copy[j + 1])
				ft_swap(&copy[j], &copy[j + 1]);
	}
	free(copy);
	return (copy);
}
