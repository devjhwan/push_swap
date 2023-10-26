/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:44:53 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 23:44:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (stack->cur_size >= 1)
	{
		stack->last = (stack->last + 1) % stack->size;
		stack->arr[stack->last] = stack->arr[stack->first];
		stack->first = (stack->first + 1) % stack->size;
	}
}

void	ra(t_stack *stack)
{
	rotate(stack);
}

void	rb(t_stack *stack)
{
	rotate(stack);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
