/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:05:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

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
	stack->first = 0;
	stack->last = 0;
	stack->cur_size = 0;
	return (stack);
}
