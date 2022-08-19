/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:20:03 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 21:37:55 by wricky-t         ###   ########.fr       */
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
int	binary_search(t_stack *stack, int target, int top, int btm)
{
	int	mid;
	int	*items;

	items = stack->items;
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
		return (binary_search(stack, target, mid + 1, btm));
	return (binary_search(stack, target, top, mid - 1));
}

// void	rotate_decider(t_stack *dest)
// {
	
// }
