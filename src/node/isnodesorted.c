/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnodesorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:47:44 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:47:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnodesorted(t_node *node)
{
	t_stack	*stack;
	int		i;
	int		count;
	int		n;

	stack = node->stack_a;
	if (stack->cur_size != stack->size)
		return (0);
	i = stack->first;
	count = 0;
	n = stack->size - 1;
	while (count < n)
	{
		if (stack->arr[i] > stack->arr[(i + 1) % stack->size])
			return (0);
		i = (i + 1) % stack->size;
		count++;
	}
	return (1);
}
