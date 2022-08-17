/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:15:12 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/17 19:22:13 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Initialize the stack
 *
 * 1. Set capacity as the number of arguments
 * 2. Set top(index of top item) as -1, meaning nothing is in there
 * 3. Calloc items with the number of arguments - 1 (exclude program name)
 * 4. Check if malloc successful or not, if not return -1. Else return 1.
 **/
int	init_stack(t_stack *stack, int num_of_arg)
{
	stack->capacity = num_of_arg;
	stack->top = -1;
	stack->items = ft_calloc(num_of_arg, sizeof(int));
	if (stack->items == NULL)
		return (-1);
	return (1);
}

/**
 * Push argument onto stack
 *
 * Since the first argument need to be on the top of the stack, so push the
 * last arg onto the stack first until when i == 1, meaning not including the
 * program name.
 **/
void	push_args(t_stack *stack, int *args)
{
	int	i;
	int	arg;

	i = -1;
	while (++i < stack->capacity)
	{
		arg = args[i];
		push(stack, arg);
	}
}

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
 * Check if a stack is sorted
 * 
 * Ideally, if the stack is sorted, the topmost item will be the smallest; largest
 * at the bottom. So, iterate through from the top, compare the current item with
 * the item below it. If the current item is greater than the next item, meaning
 * it's not sorted, return 0 to the caller. If we manage compare to the last item,
 * meaning it's sorted, return 1 to the caller. Notice that we only compare until
 * i greater than 0, meaning until index 1. This is to avoid the function to
 * overlook.
**/
int	check_if_sorted(t_stack *stack)
{
	int	i;
	int	*items;

	i = -1;
	items = stack->items;
	while (++i < stack->capacity - 1)
	{
		if (items[i] > items[i - 1])
			return (0);
		i++;
	}
	return (1);
}
