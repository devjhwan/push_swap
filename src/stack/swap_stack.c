/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:44:27 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 22:44:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;
	int	first;
	int	second;

	if (stack->cur_size >= 2)
	{
		first = stack->first;
		second = (stack->first + 1) % stack->size;
		tmp = stack->arr[first];
		stack->arr[first] = stack->arr[second];
		stack->arr[second] = tmp;
	}
}
