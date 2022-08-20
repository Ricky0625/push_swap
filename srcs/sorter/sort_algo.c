/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:04:19 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/20 18:04:17 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
void	insertion_sort(t_stack *org, t_stack *dest)
{
	int top_org;
	int loc;

	while (is_empty(org) != 1)
	{
		top_org = peek(org);
		loc = binary_search(dest, top_org, 0, dest->btm);
		give_way(dest, loc);
		push_top(org, dest, PA);
		while (peek(dest) > peek(org) && peek(org) > dest->items[dest->btm])
			push_top(org, dest, PA);
		restorer(dest);
	}
}

/**
 * Quick sort here.
**/ 
// void	quick_sort();