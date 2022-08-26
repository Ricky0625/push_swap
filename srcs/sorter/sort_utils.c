/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:20:03 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/24 16:04:01 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Find the smallest item in the stack and return it's position (index)
 * 
 * Assume the smallest item is on the top. Iterate through the items,
 * if there is an item that is smaller than the smallest (what we assume),
 * update smallest to the item's index.
 * 
 * Return smallest, which is the index of smallest item at the end.
**/
int	find_largest(t_stack *stack)
{
	int	*items;
	int	index;
	int	largest;

	items = stack->items;
	index = 1;
	largest = 0;
	while (index <= stack->btm)
	{
		if (items[index] > items[largest])
			largest = index;
		index++;
	}
	return (largest);
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
 * Smart rotate
 * 
 * Calculate the distance between the location (index) with the target
 * stacks's top index and btm index.
 * If the distance to top is <= distance to btm, do Rx (RA or RB)
 * If the distance to btm is < distance to top, do RRx (RRA or RRB)
 * The idea is to move the location to the top of the stack.
 * 
 * Do how many times? 'Distance' times. For example, distance to top is 3,
 * then do 3 times. Notice that when calculate the distance to btm, we need
 * to add extra one. Because with only 'distance to btm', we only can move
 * the location to the btm. So in order to sent it to the top, we need to
 * do extra one RRx.
**/
static void	smart_rotate(t_stkgrp *stacks, int location, char stk)
{
	t_stack	*target;
	int		dist_to_top;
	int		dist_to_btm;
	int		rrx;
	int		rx;

	target = stacks->a;
	rrx = RRA;
	rx = RA;
	if (stk == 'B')
	{
		target = stacks->b;
		rrx = RRB;
		rx = RB;
	}
	dist_to_top = location;
	dist_to_btm = target->btm - location + 1;
	if (dist_to_top <= dist_to_btm)
		while (--dist_to_top >= 0)
			r_instr(stacks, rx, 1);
	else if (dist_to_btm < dist_to_top)
		while (--dist_to_btm >= 0)
			r_instr(stacks, rrx, 1);
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
 * 2. If the location is equal to the target's btm, meaning it's smaller than
 * 	  the item at the bottom. Do RRx to move the 'seat' up for the new item.
 * 2. Do smart rotate.
**/
void	give_way(t_stkgrp *stacks, int location, char stk)
{
	t_stack	*target;
	int		rrx;

	target = stacks->a;
	rrx = RRA;
	if (stk == 'B')
	{
		target = stacks->b;
		rrx = RRB;
	}	
	if (location > target->btm || location == 0)
		return ;
	if (location == target->btm)
	{
		r_instr(stacks, rrx, 1);
		return ;
	}
	smart_rotate(stacks, location, stk);
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
void	restorer(t_stkgrp *stacks, char stk)
{
	t_stack	*target;
	int		smallest;

	target = stacks->a;
	if (stk == 'B')
		target = stacks->b;
	smallest = find_smallest(target);
	if (smallest == 0)
		return ;
	smart_rotate(stacks, smallest, stk);
}
