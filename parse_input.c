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

#include <stdlib.h>
#include "push_swap.h"

#define MAX 2147483648
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define DUPLICATED 1
#define CORRECT 0

#define SUCCESSFUL 0
#define ERROR 1

int	count_arguments(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			else if (argv[i][j] != ' ')
			{
				count++;
				while (argv[i][j] != ' ' && argv[i][j] != '\0')
					j++;
			}
		}
		i++;
	}
	return (count);
}

long long int	ft_atoi(char *arg, int *i)
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

int	check_duplicate(t_stack *stack_a, int num)
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

int	fill_stack(t_stack *stack_a, char *arg)
{
	int				i;
	int				sign;
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
		stack_a->arr[stack_a->cur_size] = (int)num;
		stack_a->cur_size++;
		if (arg[i] != ' ' && arg[i] != '\0')
			return (ERROR);
	}
	return (SUCCESSFUL);
}

void	*parse_input(t_stack **stack_a, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = *stack_a;
	stack->size = count_arguments(argv);
	stack->arr = (int *)malloc(sizeof(int) * stack->size);
	if (stack->arr == NULL)
		return (NULL);
	stack->cur_size = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (fill_stack(stack, argv[i]) != SUCCESSFUL)
			return (NULL);
		i++;
	}
	return (stack);
}
