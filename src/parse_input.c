/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:55:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 21:55:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#define MAX 2147483648
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define DUPLICATED 1
#define CORRECT 0
#define SUCCESSFUL 0
#define ERROR 1

static long long int	ft_atoi(char *arg, int *i)
{
	long long int	num;
	int				sign;

	num = 0;
	sign = 1;
	if (arg[*i] == '+' || arg[*i] == '-')
	{
		if (arg[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (arg[*i] >= '0' && arg[*i] <= '9' && num <= MAX)
	{
		num = num * 10 + arg[*i] - '0';
		(*i)++;
	}
	num *= sign;
	return (num);
}

static int	check_duplicate(t_stack *stack_a, int num)
{
	int	i;

	i = 0;
	while (i < stack_a->cur_size)
	{
		if (stack_a->arr[i] == num)
			return (DUPLICATED);
		i++;
	}
	return (CORRECT);
}

static int	fill_stack(t_stack *stack_a, char *arg)
{
	int				i;
	long long int	num;

	i = 0;
	while (arg[i] != '\0')
	{
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '\0')
			return (SUCCESSFUL);
		num = ft_atoi(arg, &i);
		if (num > INT_MAX || num < INT_MIN)
			return (ERROR);
		if (check_duplicate(stack_a, (int)num) == DUPLICATED)
			return (ERROR);
		stack_a->arr[stack_a->last] = (int)num;
		stack_a->last++;
		if (arg[i] != ' ' && arg[i] != '\0')
			return (ERROR);
	}
	stack_a->cur_size = stack_a->last;
	return (SUCCESSFUL);
}

void	*parse_input(t_stack **stack_a, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (fill_stack(*stack_a, argv[i]) != SUCCESSFUL)
			return (NULL);
		i++;
	}
	return (stack_a);
}
