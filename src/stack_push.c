/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:49:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 22:49:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *origin, t_stack *destination)
{
	int	o_first;
	int d_first;

	if (origin->cur_size >= 1)
	{
		o_first = origin->first;
		d_first = destination->first - 1;
		if (d_first < 0)
			d_first = destination->size - 1;
		destination->arr[d_first] = origin->arr[o_first];
		destination->first = d_first;
		origin->first = (o_first + 1) % origin->size;
		destination->cur_size++;
		origin->cur_size--;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}
