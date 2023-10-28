/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:49:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 22:49:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_stack(t_stack *origin, t_stack *dest)
{
	if (origin->cur_size >= 1)
	{
		dest->first = dest->first - 1;
		if (dest->first < 0)
			dest->first = dest->size - 1;
		dest->arr[dest->first] = origin->arr[origin->first];
		origin->first = (origin->first + 1) % origin->size;
		dest->cur_size++;
		origin->cur_size--;
	}
}
