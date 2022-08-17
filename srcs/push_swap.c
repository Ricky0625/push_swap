/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:05:32 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/17 19:26:02 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stkgrp *stacks)
{
	t_stack *a;
	t_stack *b;
	int	i;

	a = stacks->a;
	b = stacks->b;
	i = -1;
	printf("=== A === STACK === B ===\n");
	// printf("capacity:\t\t%d\n", stack->capacity);
	// printf("top item's index:\t%d\n\n", stack->top);
	while (++i < stacks->a->capacity)
	{
		// printf("| %d |\n", stack->items[i]);
		printf("| %d\t| %d\t", a->items[i], i);
		if (i <= b->capacity)
			printf("| %d\t|", b->items[i]);
		printf("\n");
	}
	printf("========================\n\n");
}

// somewhere around the main function has a leak
int	main(int ac, char **av)
{
	int			*args;
	int			num_of_args;
	t_stack		stack_a;
	t_stack		stack_b;
	t_stkgrp	stacks;

	if (ac == 1)
		exit(EXIT_FAILURE);
	num_of_args = 0;
	args = check_arguments(ac, av, &num_of_args);
	init_stack(&stack_a, num_of_args);
	init_stack(&stack_b, num_of_args);
	push_args(&stack_a, args);
	// if (check_if_sorted(&stack_a) == 1)
	// {
	// 	ft_putstr_fd("[ERROR]: Already sorted before sort!\n", 1);
	// 	exit(EXIT_SUCCESS);
	// }
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	print_stack(&stacks);
	return (0);
}
