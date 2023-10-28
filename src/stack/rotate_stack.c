/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:44:53 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 23:44:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_stack(t_stack *stack)
{
	if (stack->cur_size >= 2)
	{
		stack->last = stack->first;
		stack->first = (stack->first + 1) % stack->size;
	}
}
