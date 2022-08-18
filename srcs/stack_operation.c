/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:48:39 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 16:12:08 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Push item onto stack
 * 
 * When push new item onto stack, the new item should be at index 0
 * So, all the previous items should move down 1 step
 * After that, at index 0, place the new item.
 * btm++, because got new item infront
**/
void	push(t_stack *stack, int item)
{
	stack->btm++;
	stack->items[stack->btm] = item;
}

/**
 * Pop item out of stack
 * 
 * When pop the topmost item out of stack, starting from index 1, move all
 * item up one slot.
 * clear the item at btm (previous) to 0
 * then do btm-- (decrement bottom index)
**/
void	pop(t_stack *stack)
{
	int	i;
	int	*items;

	i = 1;
	items = stack->items;
	while (i <= stack->btm)
	{
		ft_swap(&items[i - 1], &items[i]);
		i++;
	}
	items[stack->btm] = 0;
	stack->btm--;
}

/**
 * Check if stack is empty
 * 
 * 1: Empty
 * 0: Not empty
**/
int	is_empty(t_stack *stack)
{
	return (stack->btm == -1);
}

/**
 * Check if stack if full
 * 
 * 1: Full
 * 2. Not full
**/
int	is_full(t_stack *stack)
{
	return (stack->btm == stack->capacity - 1);
}

/**
 * Peek
 * 
 * Get the value of the topmost item
**/
int	peek(t_stack *stack)
{
	return (stack->items[0]);
}
