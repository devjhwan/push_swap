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

#include <stdio.h>
#include "push_swap.h"

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

/*
	for (int i = 0; i < stack_a->size; i++)
		printf("%d\n", stack_a->arr[i]);
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack(count_arguments(argv));
	if (stack_a == NULL)
		return (0);
	if (parse_input(&stack_a, argv) == NULL)
	{
		free_stack(stack_a);
		ft_putstr("Error\n");
		return (0);
	}
	for (int i = 0; i < stack_a->size; i++)
		printf("%d\n", stack_a->arr[i]);
	stack_b = init_stack(stack_a->size);
}
