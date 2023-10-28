/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:54:59 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 23:55:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->cur_size >= 2)
	{
		stack->first = stack->last;
		stack->last = stack->last - 1;
		if (stack->last < 0)
			stack->last = stack->size - 1;
	}
}
