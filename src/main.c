/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:41:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 20:41:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

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

int	init_variables(t_stack **stack_a, t_stack **stack_b, char **argv)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*stack_a = init_stack(count_arguments(argv));
	if (*stack_a == NULL)
		return (FAIL);
	if (parse_input(*stack_a, argv) == NULL)
	{
		ft_putstr("Error\n");
		return (FAIL);
	}
	*stack_b = init_stack((*stack_a)->size);
	if (*stack_b == NULL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	if (init_variables(&stack_a, &stack_b, argv) == FAIL)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
