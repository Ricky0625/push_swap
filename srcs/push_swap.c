/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:05:32 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 15:40:24 by wricky-t         ###   ########.fr       */
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
	int		a_cap;

	a = stacks->a;
	b = stacks->b;
	i = -1;
	j = 0;
	a_cap = a->btm;
	printf("====== A ======         ====== B ======\n");
	while (++i <= stacks->a->btm)
	{
		printf("| %11d | %d\t", a->items[i], i);
		if (a_cap <= b->btm)
		{
			printf("| %-11d | %d", b->items[j], j);
			j++;
		}
		else
			printf("|             |");
		printf("\n");
		a_cap--;
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
	if (check_if_sorted(&stack_a) == 1)
	{
		ft_putstr_fd("[ERROR]: Already sorted before sort!\n", 1);
		exit(EXIT_SUCCESS);
	}
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	print_stack(&stacks, 1);
	return (0);
}
