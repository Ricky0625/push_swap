/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:43:21 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 16:45:55 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * Ermmm... Just to swap two value?
 **/
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Swap top two value
 *
 * btm	: the index of btm item
 *
 * 1. Check if it's empty or only one item (btm == 0)
 * 2. Swap top two item
 **/
void	swap_top(t_stack *stack, int instr)
{
	int	btm;

	btm = stack->btm;
	if (is_empty(stack) == 1 || btm == 0)
		return ;
	ft_swap(&stack->items[0], &stack->items[1]);
	print_instr(instr);
}

/**
 * Push top from origin stack to destination stack
 *
 * item : the item that being pushed
 *
 * 1. Check if origin is empty or destination is full
 * 2. Get the origin topmost item, store it in item
 * 3. Pop the origin topmost item
 * 4. Push the item to destination stack
 *
 * Since i'm not using conventional way to construct my stacks, where the index
 * of top item suppose to be the end of an array, my top item is actually the
 * start of the array, which means index 0. So when we push the top item of
 * the stack, index 0 will be empty and length still remain. The length suppose
 * to be decremented as well. So, to solve that, after I push one item, I
 * have to shift all the items below index 0, to the front one space.
 **/
void	push_top(t_stack *org, t_stack *dest, int instr)
{
	int	i;
	int	item;

	if (is_empty(org) == 1 || is_full(dest))
		return ;
	item = peek(org);
	pop(org);
	push(dest, item);
	i = dest->btm;
	if (i > 0)
	{
		while (i > 0)
		{
			ft_swap(&dest->items[i - 1], &dest->items[i]);
			i--;
		}
	}
	print_instr(instr);
}

/**
 * Push n item from a stack to another based on the instruction
 *
 * stack	: the origin stack
 * new_btm	: the new bottom index
 * while the origin stack is not empty and the bottom index of stack
 * is not the new bottom index, keep pushing
 **/
void	push_n_item(t_stkgrp *stacks, int instr, int n)
{
	t_stack	*stack;
	int		new_btm;

	stack = NULL;
	if (instr == PA)
		stack = stacks->b;
	else if (instr == PB)
		stack = stacks->a;
	new_btm = stack->btm - n;
	while (is_empty(stack) != 1 && stack->btm != new_btm)
		p_instr(stacks, instr);
}

/**
 * Rotate or rotate the stack
 *
 * RRA, RRB. Last item becomes the first one.
 * Start from the last item of the array, swap it with the one above it.
 * Keep doing this until the last item is at the top.
 *
 * RA, RB. First item becomes the last one.
 * Start from the first item of the array. swap it with the one below it.
 * Keep doing this until the last itme is at the bottom.
 **/
void	rotate_stk(t_stack *stack, int instr, int print)
{
	int	start;
	int	iter;

	iter = stack->btm;
	start = 0;
	if (instr == RRA || instr == RRB)
	{
		start = stack->btm;
		while (start > 0)
		{
			ft_swap(&stack->items[start], &stack->items[start - 1]);
			start--;
		}
	}
	else if (instr == RA || instr == RB)
	{
		while (start < iter)
		{
			ft_swap(&stack->items[start], &stack->items[start + 1]);
			start++;
		}
	}
	if (print == 1)
		print_instr(instr);
}
