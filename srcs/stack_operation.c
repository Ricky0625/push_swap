/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:48:39 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 12:16:47 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Push item onto stack
 * 
 * 1. Increment top
 * 2. Push new item to the stack
**/
void	push(t_stack *stack, int item)
{
	stack->top++;
	stack->items[stack->top] = item;
}

/**
 * Pop item out of stack
 * 
 * 1. Set what's on top to 0
 * 2. Decrement top
**/
void	pop(t_stack *stack)
{
	stack->items[stack->top] = 0;
	stack->top--;
}

/**
 * Check if stack is empty
 * 
 * 1: Empty
 * 0: Not empty
**/
int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

/**
 * Check if stack if full
 * 
 * 1: Full
 * 2. Not full
**/
int	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

/**
 * Peek
 * 
 * Get the value of the topmost item
**/
int	peek(t_stack *stack)
{
	return (stack->items[stack->top]);
}
