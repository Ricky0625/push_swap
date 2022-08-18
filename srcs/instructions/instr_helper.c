/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:40 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 20:59:43 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
 * Push all item from a stack to another based on the instruction
 * 
 * stack: the origin stack
 * while the origin stack is not empty push the top item to the another stack
**/
void	push_all(t_stkgrp *stacks, int instr)
{
	t_stack	*stack;

	if (instr == PA)
		stack = stacks->b;
	else if (instr == PB)
		stack = stacks->a;
	else
		return ;
	while (is_empty(stack) != 1)
		p_instr(stacks, instr);
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
