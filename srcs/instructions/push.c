/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:14:06 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 16:40:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Push top from origin stack to destination stack
 * 
 * item : the item that being pushed
 * 1. Check if origin is empty or destination is full
 * 2. Get the origin topmost item, store it in item
 * 3. Pop the origin topmost item
 * 4. Push the item to destination stack
**/
static void	push_top(t_stack *org, t_stack *dest)
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
}

/**
 * Execute instruction PA & PB
 * 
 * a    : stack a
 * b    : stack b
 * 
 * PA, origin is stack b, destination is stack a
 * PB, origin is stack a, destination is stack b
 * 
 * After push, print instruction no matter it's sucessful or not
**/
void	p_instr(t_stkgrp *stacks, int instr)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (instr == PA)
		push_top(b, a);
	else if (instr == PB)
		push_top(a, b);
	print_instr(instr);
}
