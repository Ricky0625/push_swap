/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:47:29 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/17 19:11:01 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check for duplicates
 *
 * i	: for outer loop (main target)
 * j	: for inner loop (the members)
 * cmp	: comparision result
 * size	: size of the main target, will be used for strncmp
 *
 * 1. Main target will only be up to the last 2nd string the reason is
 * 	  because if we main target is the last string, the inner loop will not
 * 	  run anywhere, so why not just stop at the last 2nd string
 * 2. The compared target will be i + 1, will be using strncmp to get the
 *    comparison between them. If cmp is 0 means they are identical.
 **/
static void check_duplicates(int num, char **tab)
{
	int i;
	int j;
	int cmp;
	size_t size;

	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		size = ft_strlen(tab[i]);
		while (j < num)
		{
			if (ft_strlen(tab[j]) > size)
				size = ft_strlen(tab[j]);
			cmp = ft_strncmp(tab[i], tab[j], size);
			if (cmp == 0)
			{
				ft_putstr_fd("[ERROR]: Duplicate arguments!\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

/**
 * Check for non-integer arguments
 *
 * i		: for outer loop (current string)
 * str		: store the current string
 * is_digit	: check if a character is a digit
 *
 * 1. Iterate through the argument list using the outer loop
 * 2. Iterate through each of the character of the current string using
 * 	  the inner loop
 * 3. Specifically check if the start of the str is a '-' sign
 * 	  If that's the case, increment pointer to char to the next character
 * 	  because this might be a negative integer value
 * 3. For each character, check if it's a digit ('0' - '9')
 **/
static void check_is_int(int num, char **tab)
{
	int i;
	char *str;
	int is_digit;

	i = -1;
	while (++i < num)
	{
		str = tab[i];
		if (str[0] == '-')
			str++;
		while (*str != '\0')
		{
			is_digit = ft_isdigit(*str);
			if (is_digit == 0)
			{
				ft_putstr_fd("[ERROR]: Non-integer arguments found!\n", 2);
				exit(EXIT_FAILURE);
			}
			str++;
		}
	}
}

/**
 * Get the args, turn them into integer
 *
 * 1. While loop is used to iterate through the argument list
 * 2. Convert the argument into integer
 * 3. If argument is less than INT_MIN or greater than INT_MAX, exit program
 * 4. Else, put the converted arg into array
 * 5. Return arg array at the end
 **/
static int *get_args(int num, char **tab)
{
	int *args;
	long out;
	int index;

	args = ft_calloc(num, sizeof(int));
	index = -1;
	while (++index < num)
	{
		out = ft_atol(tab[index]);
		if (out < INT_MIN || out > INT_MAX)
		{
			ft_putstr_fd("[ERROR]: Integer out of range!\n", 2);
			free(args);
			exit(EXIT_FAILURE);
		}
		args[index] = out;
	}
	return (args);
}

/**
 * Check arguments
 *
 * The process of checking the arguments: (order is crucial)
 * 1. Check if ac is only 1, meaning invalid usage, should exit
 * 2. Check if ac is only 2, meaning one arg only, meaning already sorted
 * 3. Check if there's duplicates
 * 	  The order of this one actually doesn't matter :D
 * 4. Check if there's non-integer arguments
 *    Must before get_args
 * 5. Once the arguments could pass the previous two test, meaning it's ready
 *    to be converted into integer.
 * 6. Check if the arguments are sorted already or not, if the arguments could
 *    pass this test, meaning not sorted, need to sort them
 *
 * When the main function pass through all these checking, meaning it's
 * ok to push those arguments onto stack and begin to sort
 **/
int *check_arguments(int ac, char **av, int *num)
{
	char *joined_args;
	char **args_tab;
	int *args;

	joined_args = join_args(ac, av);
	args_tab = ft_split(joined_args, ' ');
	*num = get_num_of_args(args_tab);
	check_duplicates(*num, args_tab);
	check_is_int(*num, args_tab);
	if (*num == 1)
		exit(EXIT_SUCCESS);
	args = get_args(*num, args_tab);
	free(joined_args);
	free_tabs(args_tab);
	return (args);
}
