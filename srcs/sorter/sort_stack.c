/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:05:17 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/18 21:15:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(t_stkgrp *stacks, int num_of_arg)
{
	t_stack	*a;
	// t_stack	*b;

	a = stacks->a;
	// b = stacks->b;
	if (check_if_sorted(a) == 1)
	{
		ft_putstr_fd("[ERROR]: Already sorted before sort!\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (num_of_arg == 2)
		s_instr(stacks, SA);
	else if (num_of_arg == 3)
		sort_three(stacks, a);
	// else if (num_of_arg == 5)
	// 	sort_five(stacks);
	// else
	// 	insertion_sort(stacks);
}
