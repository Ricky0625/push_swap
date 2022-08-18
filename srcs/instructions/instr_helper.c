/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:40 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 19:59:23 by wricky-t         ###   ########.fr       */
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
	t_stack *stack;

	if (instr == PA)
		stack = stacks->b;
	else if (instr == PB)
		stack = stacks->a;
	else
		return ;
	while (is_empty(stack) != 1)
		p_instr(stacks, instr);	
}
