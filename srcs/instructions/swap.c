/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:18:31 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 15:53:37 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Swap top two value
 * 
 * top	: the index of top item
 * 1. Check if it's empty or only one item (btm == 0)
 * 2. Swap top two item
**/
static void	swap_top(t_stack *stack)
{
	int	btm;

	btm = stack->btm;
	if (is_empty(stack) == 1 || btm == 0)
		return ;
	ft_swap(&stack->items[0], &stack->items[1]);
}

/**
 * Execute instruction SA, SB & SS
 * 
 * a	: stack a
 * b	: stack b
 * 1. if instr is SA, swap_top(a)
 * 2. if instr is SB, swap_top(b)
 * 3. if instr is SS, swap_top(a) then swap_top(b)
 * 
 * After swap, print the instruction, even if the top two not swapped
**/
void	s_instr(t_stkgrp *stacks, int instr)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (instr == SA)
		swap_top(a);
	else if (instr == SB)
		swap_top(b);
	else if (instr == SS)
	{
		swap_top(a);
		swap_top(b);
	}
	print_instr(instr);
}
