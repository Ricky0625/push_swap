/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:18:31 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/20 17:56:31 by wricky-t         ###   ########.fr       */
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
void swap_top(t_stack *stack, int instr)
{
	int btm;

	btm = stack->btm;
	if (is_empty(stack) == 1 || btm == 0)
		return;
	ft_swap(&stack->items[0], &stack->items[1]);
	print_instr(instr);
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
void s_instr(t_stkgrp *stacks, int instr)
{
	t_stack *a;
	t_stack *b;

	a = stacks->a;
	b = stacks->b;
	if (instr == SA)
		swap_top(a, instr);
	else if (instr == SB)
		swap_top(b, instr);
	else if (instr == SS)
	{
		swap_top(a, instr);
		swap_top(b, instr);
	}
	// print_stack(stacks, 0);
}
