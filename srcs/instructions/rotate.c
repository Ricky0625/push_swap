/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:11:59 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 17:13:42 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Push all item from origin stack to destination stack
 * 
 * While the origin stack is not empty (top != -1),
 * i.	Get the topmost item, store it into item
 * ii.	Pop the topmost item
 * iii.	Push the item into the destination stack
**/
// MOVE TO INSTR_HELPER
// static void	push_all(t_stack *org, t_stack *dest)
// {
// 	int	item;

// 	while (org->top != -1)
// 	{
// 		item = peek(org);
// 		pop(org);
// 		push(dest, item);
// 	}
// }

/**
 * Rotate or rotate the stack
 * 

**/
static void	rotate_stk(t_stack *stack, int instr)
{
	int	start;
	int	iter;

	iter = stack->btm;
	start = 0;
	if (instr == RRA || instr == RRB || instr == RRR)
	{
		start = stack->btm;
		while (start > 0)
		{
			ft_swap(&stack->items[start], &stack->items[start - 1]);
			start--;
		}
	}
	else
	{
		while (start < iter)
		{
			ft_swap(&stack->items[start], &stack->items[start + 1]);
			start++;
		}
	}
}

/**
 * Execute instruction RA, RB, RR
 * 
 * a	: stack a
 * b	: stack b
 * 1. if instr is RA, rotate_stk(a)
 * 2. if instr is RB, rotate_stk(b)
 * 3. if instr is RR, rotate_stk(a) then rotate_stk(b)
 * 4. if instr is RRA, rotate_stk(a)
 * 5. if instr is RRB, rotate_stk(b)
 * 6. if instr is RRR, rotate_stk(a) then rotate_stk(b)
 * 
 * For RRx instructions, rotate_stk will determine how many rotation is needed.
 * 
 * After rotate, print the instruction no matter what
**/
void	r_instr(t_stkgrp *stacks, int instr)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (instr == RA)
		rotate_stk(a, instr);
	else if (instr == RB)
		rotate_stk(b, instr);
	else if (instr == RR)
	{
		rotate_stk(a, RA);
		rotate_stk(b, RB);
	}
	else if (instr == RRA)
		rotate_stk(a, instr);
	else if (instr == RRB)
		rotate_stk(b, instr);
	else if (instr == RRR)
	{
		rotate_stk(a, RRA);
		rotate_stk(b, RRB);
	}
	print_instr(instr);
}
