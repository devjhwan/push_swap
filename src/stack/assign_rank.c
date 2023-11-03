/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 03:10:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 03:10:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

static void	assign_sorted_index(t_stack *origin, t_stack *sorted_stack, \
							t_stack *ref_stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < origin->size)
	{
		j = 0;
		while (j < origin->size)
		{
			if (sorted_stack->arr[i] == ref_stack->arr[j])
			{
				origin->arr[j] = i + 1;
				break;
			}
			j++;
		}
		i++;
	}
}

int	assign_rank(t_stack	*stack)
{
	t_stack	*sorted_stack;
	t_stack	*ref_stack;
	
	sorted_stack = clone_stack(stack);
	if (sorted_stack == NULL)
		return (ERROR);
	sort_stack(sorted_stack);
	ref_stack = clone_stack(stack);
	if (ref_stack == NULL)
		return (free_stack(sorted_stack), ERROR);
	assign_sorted_index(stack, sorted_stack, ref_stack);
	free_stack(sorted_stack);
	free_stack(ref_stack);
	return (SUCCESS);
}
