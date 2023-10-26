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

void	free_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}
