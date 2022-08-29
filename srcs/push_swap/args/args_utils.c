/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:07:45 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 15:21:51 by wricky-t         ###   ########.fr       */
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
char *join_args(int ac, char **av)
{
	int index;
	int used;
	char *with_sp;
	char *joined;
	char *temp;

	index = 1;
	used = 0;
	joined = av[1];
	temp = NULL;
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
int get_num_of_args(char **args)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (args[++i] != NULL)
		num++;
	return (num);
}

/**
 * Free array of strings (used after ft_split)
 **/
void free_tabs(char **args)
{
	int i;

	i = -1;
	while (args[++i] != NULL)
		free(args[i]);
	free(args);
}