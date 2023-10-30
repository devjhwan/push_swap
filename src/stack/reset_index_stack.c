/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_index_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 04:03:44 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 04:03:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

int	reset_index_stack(t_stack *stack, t_stack *sorted_stack)
{
	int	i;
	int	j;
	int	ref;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * stack->size);
	if (arr == NULL)
		return (ERROR);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		ref = sorted_stack->arr[i];
		while (stack->arr[j] != ref)
			j++;
		sorted_stack->arr[i] = i + 1;
		arr[j] = i + 1;
		i++;
	}
	while (i > 0)
	{
		i--;
		stack->arr[i] = arr[i];
	}
	return (free(arr), SUCCESS);
}
