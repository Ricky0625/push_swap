/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:21:41 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 21:17:15 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stkgrp *stacks, t_stack *main)
{
	int		top;
	int		mid;
	int		btm;

	top = main->items[0];
	mid = main->items[1];
	btm = main->items[2];
	if (btm > mid && btm < top)
		r_instr(stacks, RA);
	else if (top > btm && top < mid)
		r_instr(stacks, RRA);
	else if (top > mid && top < btm)
		s_instr(stacks, SA);
	else if (top > mid && mid > btm)
	{
		s_instr(stacks, SA);
		r_instr(stacks, RRA);
	}
	else if (btm > top && mid > btm)
	{
		r_instr(stacks, RRA);
		s_instr(stacks, SA);
	}
}

void	sort_five(t_stkgrp *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	// push 2 item to stack b no matter what
	push_n_item(stacks, PB,2);
	// sort the stack a using sort_three since it has three item
	sort_three(stacks, a);
}
