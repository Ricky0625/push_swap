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
 * minimum and maximum index to look at.
**/
int	binary_search(t_stack *stack, int target, int low, int high)
{
	int	mid;
	int	*items;

	items = stack->items;
	if (high <= low)
	{
		if (target > items[low])
			return (low + 1);
		return (low);
	}
	mid = (low + high) / 2;
	if (target == items[mid])
		return (mid + 1);
	if (target > items[mid])
		return (binary_search(stack, target, mid + 1, high));
	return (binary_search(stack, target, low, mid - 1));
}

// void	rotate_decider(t_stack *dest)
// {
	
// }