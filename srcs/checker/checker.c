/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:24:04 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 17:23:43 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_and_exit(t_stack *stack)
{
	if (check_if_sorted(stack) == 1)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("KO\n", 2);
	exit(EXIT_FAILURE);
}

int	convert_instr(char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		return (SA);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		return (SB);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		return (SS);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		return (PA);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		return (PB);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		return (RA);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		return (RB);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		return (RR);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		return (RRA);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		return (RRB);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		return (RRR);
	else
		return (-1);
}

void	execute_instr(t_stkgrp *stacks, int instr)
{
	if (instr == SA || instr == SB || instr == SS)
		s_instr(stacks, instr);
	else if (instr == PA || instr == PB)
		p_instr(stacks, instr);
	else if (instr == RA || instr == RB || instr == RR
		|| instr == RRA || instr == RRB || instr == RRR)
		r_instr(stacks, instr, 0);
	return ;
}

void	read_and_execute(t_stkgrp *stacks)
{
	char	*str;
	int		instr;
	t_stack	*a;

	a = stacks->a;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			check_and_exit(a);
		instr = convert_instr(str);
		if (instr == -1)
		{
			ft_putstr_fd("ERROR\n", 2);
			exit(2);
		}
		execute_instr(stacks, instr);
	}
}

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
	read_and_execute(&stacks);
	free(args);
	free(stack_a.items);
	free(stack_b.items);
	return (0);
}
