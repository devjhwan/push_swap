/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:54:59 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 23:55:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate(t_stack *stack)
{
	if (stack->cur_size >= 1)
	{
		stack->first = stack->last;
		stack->last = stack->last - 1;
		if (stack->last < 0)
			stack->last = stack->size - 1;
	}
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
