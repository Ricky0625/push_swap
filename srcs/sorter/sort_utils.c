/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:20:03 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/20 17:56:50 by wricky-t         ###   ########.fr       */
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
int	binary_search(t_stack *dest, int target, int top, int btm)
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
 * Detect natural runs in a stack
 * 
 * Natural runs: Already-ordered elements like 1,2,4,6,8,9 or in descending
 * For this function, we only detect natural runs in descending order
 * The function will return an array of two index value if there is a run.
 * nruns = {start, end};
 * 
 * Will assume the start of a natural run start from index 0, so nruns[0] = 0.
 * Iterate through the items, as long as it's less than the target's btm
 * If item at index is less than item at index + 1, meaning it's an ascending
 * order run, break the loop.
 * Check if the index is greater than 0, if yes, set natural run ending at index.
 * Else return NULL, meaning to natural run.
**/
int	*detect_runs(t_stack *target)
{
	int	index;
	int	*items;
	int	*nruns;

	index = 0;
	items = target->items;
	nruns = malloc(sizeof(int) * 2);
	nruns[0] = 0;
	while (index < target->btm)
	{
		if (items[index] < items[index + 1])
			break ;
		index++;
	}
	if (index > 0)
		nruns[1] = index;
	else
	{
		free(nruns);
		return (NULL);
	}
	return (nruns);
}

/**
 * Find the smallest item in the stack and return it's position (index)
 * 
 * Assume the smallest item is on the top. Iterate through the items,
 * if there is an item that is smaller than the smallest (what we assume),
 * update smallest to the item's index.
 * 
 * Return smallest, which is the index of smallest item at the end.
**/
int	find_smallest(t_stack *stack)
{
	int	*items;
	int	index;
	int	smallest;

	items = stack->items;
	index = 1;
	smallest = 0;
	while (index <= stack->btm)
	{
		if (items[index] < items[smallest])
			smallest = index;
		index++;
	}
	return (smallest);
}

/**
 * Give way. The function name explains it all, to give way for the new item
 * 
 * dest_btm		: destination btm index
 * dist_to_top	: distance between location to top
 * dist_to_btm	: distance between location to btm
 * 
 * 1. If location == 0 (new smallest), or location > dest_btm (new largest) do
 * 	  nothing, can push afterward and restorer will handle the rest
 * 2. If dist_to_top < dist_to_btm, do RA dist_to_top times
 * 3. If dist_to_btm < dist_to_top, do RRA dist_to_btm times
 * 4. When dist_to_top == dist_top_btm, no matter what direction, will be the
 *    same, so either one. For this function, I choose to do RA.
**/
void	give_way(t_stack *dest, int location)
{
	int	dest_btm;
	int	dist_to_top;
	int	dist_to_btm;

	dest_btm = dest->btm;
	if (location > dest_btm || location == 0)
		return ;
	if (location == dest_btm)
	{
		rotate_stk(dest, RRA);
		return ;
	}
	dist_to_top = location;
	dist_to_btm = dest_btm - location + 1;
	if (dist_to_top <= dist_to_btm)
		while (--dist_to_top >= 0)
			rotate_stk(dest, RA);
	if (dist_to_btm < dist_to_top)
		while (--dist_to_btm >= 0)
			rotate_stk(dest, RRA);
}

/**
 * Restore the stack back to ascending order
 * 
 * smallest		: the index of the smallest item
 * dest_btm		: btm index of the stack
 * dist_to_top	: distance between smallest item to top
 * dist_to_btm	: distance between smallest item to btm
 * 
 * 1. if smallest is == 0, meaning smallest ady at top, don't move
 * 2. If dist_to_top < dist_to_btm, do RA dist_to_top times
 * 3. If dist_to_btm < dist_to_top, do RRA dist_to_btm times
 * 4. When dist_to_top == dist_top_btm, no matter what direction, will be the
 *    same, so either one. For this function, I choose to do RA.
**/
void	restorer(t_stack *stack)
{
	int	smallest;
	int	dest_btm;
	int	dist_to_top;
	int	dist_to_btm;

	smallest = find_smallest(stack);
	dest_btm = stack->btm;
	if (smallest == 0)
		return ;
	dist_to_top = smallest;
	dist_to_btm = dest_btm - smallest + 1;
	if (dist_to_top < dist_to_btm)
		while (--dist_to_top >= 0)
			rotate_stk(stack, RA);
	if (dist_to_btm <= dist_to_top)
		while (--dist_to_btm >= 0)
			rotate_stk(stack, RRA);
}
