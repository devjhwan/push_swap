/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:54:33 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 03:54:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size - 1)
		{
			if (stack->arr[j] > stack->arr[j + 1])
			{
				tmp = stack->arr[j + 1];
				stack->arr[j + 1] = stack->arr[j];
				stack->arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	reverse_sort_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size - 1)
		{
			if (stack->arr[j] < stack->arr[j + 1])
			{
				tmp = stack->arr[j + 1];
				stack->arr[j + 1] = stack->arr[j];
				stack->arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
