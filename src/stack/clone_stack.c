/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:06:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:06:17 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*clone_stack(t_stack *origin_stack)
{
	t_stack	*stack_clone;
	int		i;

	stack_clone = init_stack(origin_stack->size);
	if (stack_clone == NULL)
		return (NULL);
	i = 0;
	while (i < origin_stack->size)
	{
		stack_clone->arr[i] = origin_stack->arr[i];
		i++;
	}
	stack_clone->first = origin_stack->first;
	stack_clone->last = origin_stack->last;
	stack_clone->cur_size = origin_stack->cur_size;
	return (stack_clone);
}
