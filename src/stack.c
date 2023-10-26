/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:18:45 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 22:18:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (stack->arr == NULL)
		return (free_stack(stack), NULL);
	stack->size = size;
	stack->cur_size = 0;
	return (stack);
}

t_stack *clone_stack(t_stack *origin_stack)
{
	t_stack *cloned_stack;
	int		i;

	cloned_stack = init_stack(origin_stack->size);
	if (clone_stack == NULL)
		return (NULL);
	i = 0;
	while (i < origin_stack->size)
	{
		clone_stack->arr[i] = origin_stack->arr[i];
		i++;
	}
	clone_stack->cur_size = origin_stack->cur_size;
	return (clone_stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}
