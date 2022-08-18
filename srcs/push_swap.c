/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:05:32 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 12:19:25 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * To visualize the stacks, for debugging purpose only.
**/
void	print_stack(t_stkgrp *stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = stacks->a;
	b = stacks->b;
	i = -1;
	printf("====== A ======  INDEX ====== B ======\n");
	while (++i < stacks->a->capacity)
	{
		printf("| %11d |  %4d  ", a->items[i], i);
		if (i <= b->capacity)
			printf("| %-11d |", b->items[i]);
		printf("\n");
	}
	printf("======================================\n\n");
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
	print_stack(&stacks);
	return (0);
}
