/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:05:32 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/19 18:03:23 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * To visualize the stacks, for debugging purpose only.
**/
void	print_stack(t_stkgrp *stacks, int extra_info)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		j;
	int		z;
	int		cap;
	int		max_height;

	a = stacks->a;
	b = stacks->b;
	i = -1;
	j = 0;
	z = 0;
	max_height = a->btm;
	if (b->btm > a->btm)
		max_height = b->btm;
	cap = max_height;
	printf("====== A ======         ====== B ======\n");
	while (++i <= max_height)
	{
		if (cap <= a->btm)
		{
			printf("| %11d | %-3d\t", a->items[z], z);
			z++;
		}
		else
			printf("|             |         ");
		if (cap <= b->btm)
		{
			printf("| %-11d | %d", b->items[j], j);
			j++;
		}
		else
			printf("|             |");
		printf("\n");
		cap--;
	}
	printf("=======================================\n");
	if (extra_info)
		printf("| btm:%7d |         | btm:%7d |\n\n", a->btm, b->btm);
}

/**
 * Main function of push_swap
 * 
 * 1. Check arguments
 * 2. Initialize stacks
 * 3. Push arguments onto stack a
 * 4. Sort!
**/
int	main(int ac, char **av)
{
	int			*args;
	int			num_of_args;
	t_stack		stack_a;
	t_stack		stack_b;
	t_stkgrp	stacks;

	num_of_args = 0;
	args = check_arguments(ac, av, &num_of_args);
	init_stack(&stack_a, num_of_args);
	init_stack(&stack_b, num_of_args);
	push_args(&stack_a, args);
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	sort_stack(&stacks, num_of_args);
	return (0);
}
