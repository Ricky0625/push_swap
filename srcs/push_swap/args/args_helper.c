/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:47:29 by wricky-t          #+#    #+#             */
/*   Updated: 2022/08/29 17:13:52 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

#include "../../../includes/push_swap.h"

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
static void	check_duplicates(int num, char **tab)
{
	int		i;
	int		j;
	int		cmp;
	size_t	size;

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
				ft_putstr_fd("ERROR\n", 2);
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
static void	check_is_int(int num, char **tab)
{
	int		i;
	char	*str;
	int		is_digit;

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
				ft_putstr_fd("ERROR\n", 2);
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
static int	*get_args(int num, char **tab)
{
	int		*args;
	long	out;
	int		index;

	args = ft_calloc(num, sizeof(int));
	index = -1;
	while (++index < num)
	{
		out = ft_atol(tab[index]);
		if (out < INT_MIN || out > INT_MAX)
		{
			ft_putstr_fd("ERROR\n", 2);
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
 * The process of checking the arguments:
 * 1. Join all the arguments all together to accept something like:
 * 	  " 2 1 5 6" "90 7 45 10"
 * 2. Split all the arguments using ft_split
 * 3. Get the number of arguments
 * 4. Check if there's duplicates
 * 5. Check if there's non-integer arguments (Must before get_args)
 * 5. Once the arguments could pass all test, meaning it's ready
 *    to be converted into integer. (get_args)
 * 6. Free joined args, only free if ac greater than 2, below that will
 * 	  not use free().
 * 7. Free the argument tabs.
 * 8. Return the arguemnts in the form of int *.
 **/
int	*check_arguments(int ac, char **av, int *num)
{
	char	*joined_args;
	char	**args_tab;
	int		*args;

	if (ac == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(EXIT_FAILURE);
	}
	joined_args = join_args(ac, av);
	args_tab = ft_split(joined_args, ' ');
	*num = get_num_of_args(args_tab);
	check_duplicates(*num, args_tab);
	check_is_int(*num, args_tab);
	if (*num == 1)
		exit(EXIT_SUCCESS);
	args = get_args(*num, args_tab);
	if (ac > 2)
		free(joined_args);
	free_tabs(args_tab);
	return (args);
}
