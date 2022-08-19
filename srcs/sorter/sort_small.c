/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:21:41 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/19 18:20:23 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_three(t_stkgrp *stacks, t_stack *main)
{
	int top;
	int mid;
	int btm;

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

void sort_five(t_stkgrp *stacks)
{
	t_stack *a;
	t_stack *b;
	int top_b;
	int loc;
	int *nruns;

	a = stacks->a;
	b = stacks->b;
	// n should not only be 2, if this works on other numbers of arguments
	push_n_item(stacks, PB, 2);
	sort_three(stacks, a);
	// it's working (YAY!), just need to cut down few instructions
	while (is_empty(b) != 1)
	{
		// galloping starts here, basically means push the runs to stack a
		top_b = peek(b);
		nruns = detect_runs(b);
		// if natural runs exists, check where it should be placed
		// if (nruns != NULL)
		// {
		// 	// printf("Natural runs exists!\nRuns starts at %d & ends at: %d\n", nruns[0], nruns[1]);
		// 	// natural runs starts at index 0 anyway, technically it's top_b
		// 	loc = binary_search(a, top_b, 0, a->btm);
		// 	while (nruns[1] > 0)
		// 	{
		// 		// printf("doing galloping\n");
		// 		printf("location: %d\n", loc);
		// 		printf("is bigger? %d\n", loc < a->btm && a->items[loc + 1] > b->items[nruns[1]]);
		// 		exit(1);
		// 		if (loc < a->btm && a->items[loc + 1] > b->items[nruns[1]])
		// 		{
		// 			int n = nruns[1] - nruns[0] + 1;
		// 			give_way(b, a, loc);
		// 			push_n_item(stacks, PA, n);
		// 			break;
		// 		}
		// 		else
		// 			nruns[1]--;
		// 	}
		// }
		// else
		// {
		// one by one merging process starts here
		// probably should detect run first
		loc = binary_search(a, top_b, 0, a->btm);
		give_way(b, a, loc);
		p_instr(stacks, PA);
		// }
		restorer(a);
		// print_stack(stacks, 0);
	}
}
