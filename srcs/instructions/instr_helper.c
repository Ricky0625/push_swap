/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:40 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/24 10:40:53 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Print instruction according to the instruction given
 **/
void	print_instr(int instr)
{
	if (instr == SA)
		ft_putstr_fd("sa\n", 1);
	else if (instr == SB)
		ft_putstr_fd("sb\n", 1);
	else if (instr == SS)
		ft_putstr_fd("ss\n", 1);
	else if (instr == PA)
		ft_putstr_fd("pa\n", 1);
	else if (instr == PB)
		ft_putstr_fd("pb\n", 1);
	else if (instr == RA)
		ft_putstr_fd("ra\n", 1);
	else if (instr == RB)
		ft_putstr_fd("rb\n", 1);
	else if (instr == RR)
		ft_putstr_fd("rr\n", 1);
	else if (instr == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (instr == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (instr == RRR)
		ft_putstr_fd("rrr\n", 1);
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
		swap_top(a, instr);
	else if (instr == SB)
		swap_top(b, instr);
	else if (instr == SS)
	{
		swap_top(a, instr);
		swap_top(b, instr);
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
		push_top(b, a, PA);
	else if (instr == PB)
		push_top(a, b, PB);
}

/**
 * Execute instruction RRx, Rx
 *
 * stack: the target stack
 * 
 * 1. If it's RR, call the r_instr with RA and RB but don't print instr.
 * 2. IF it's RRR, call the r_instr with RRA and RRB but don't print instr.
 * 3. Assign stack (If not RR nor RRR)
 * 	  - If it's RA or RRA, target stack set to stack A.
 *    - If it's RB or RRB, target stack set to stack B.
 * 4. If the stack is not NULL, meaning RA, RRA, RB or RRB, do rotate/reverse.
 * 5. If print is 1, meaning need to print the executed instr.
 **/
void	r_instr(t_stkgrp *stacks, int instr, int print)
{
	t_stack	*stack;

	stack = NULL;
	if (instr == RR)
	{
		r_instr(stacks, RA, 0);
		r_instr(stacks, RB, 0);
	}
	else if (instr == RRR)
	{
		r_instr(stacks, RRA, 0);
		r_instr(stacks, RRB, 0);
	}
	else if (instr == RA || instr == RRA)
		stack = stacks->a;
	else if (instr == RB || instr == RRB)
		stack = stacks->b;
	if (stack != NULL)
		rotate_stk(stack, instr, 0);
	if (print == 1)
		print_instr(instr);
}
