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

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void	*parse_input(t_stack **stack_a, char **argv);

void	free_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->arr = NULL;
	stack->size = 0;
	stack->cur_size = 0;
	return (stack);
}

/*
	for (int i = 0; i < stack_a->size; i++)
		printf("%d\n", stack_a->arr[i]);
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	if (stack_a == NULL)
		return (0);
	if (parse_input(&stack_a, argv) == NULL)
	{
		free_stack(stack_a);
		ft_putstr("Error\n");
		return (0);
	}
}
