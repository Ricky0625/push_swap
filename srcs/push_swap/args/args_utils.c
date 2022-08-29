/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:07:45 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 18:42:27 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * Join all the arguments all together
 *
 * index : use to iterate through the arguments list
 * used	 : to check whether joined has been used
 * joined: the result (all argument joined together)
 * temp	 : to temporary store 'joined' before assign to new address
 *
 * Iterate through the arguments, join the arguments with a space in between.
 *
 * The joining process (while loop) will only be running if ac is greater or
 * equal to 3. At start, av[1] will be assigned to joined. If there is more
 * than 2 args (not including program name), while loop will run. In the
 * first run, used will be 0. Then, proceed to join the string with space.
 * After this, used will be set to 1, meaning joined has been used and next
 * time before we use this, we have to free it.
 *
 * Method to free 'joined':
 * Assign 'joined' to temp, which means temp is pointing to 'joined'.
 * Since strjoin will assign new address to joined, the old address will
 * be pointed by the temp. Before next iteration, free `temp` to free the
 * previous value of 'joined'.
 **/
char	*join_args(int ac, char **av)
{
	int		index;
	int		used;
	char	*with_sp;
	char	*joined;
	char	*temp;

	index = 1;
	used = 0;
	temp = NULL;
	joined = av[1];
	while (++index < ac)
	{
		if (used == 1)
			temp = joined;
		with_sp = ft_strjoin(joined, " ");
		joined = ft_strjoin(with_sp, av[index]);
		used = 1;
		if (used == 1 && temp != NULL)
			free(temp);
		free(with_sp);
	}
	return (joined);
}

/**
 * Get number of arguments (used after ft_split)
 **/
int	get_num_of_args(char **args)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	while (args[++i] != NULL)
		num++;
	return (num);
}

/**
 * Free array of strings (used after ft_split)
 **/
void	free_tabs(char **args)
{
	int	i;

	i = -1;
	while (args[++i] != NULL)
		free(args[i]);
	free(args);
}

/**
 * Initialize the stack
 *
 * 1. Set capacity as the number of arguments
 * 2. Set btm(index of bottom item) as -1, meaning nothing is in there
 * 3. Calloc items with the number of arguments - 1 (exclude program name)
 * 4. Check if malloc successful or not, if not return -1. Else return 1.
 **/
int	init_stack(t_stack *stack, int num_of_arg)
{
	stack->capacity = num_of_arg;
	stack->btm = -1;
	stack->items = ft_calloc(num_of_arg, sizeof(int));
	if (stack->items == NULL)
		return (-1);
	return (1);
}

/**
 * Push argument onto stack
 *
 * Push each value in the args onto the stack. index 0 is the top.
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
