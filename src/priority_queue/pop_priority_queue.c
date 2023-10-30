/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_priority_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:03:38 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 03:03:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"
#include <stdlib.h>

void	*pop_priority_queue(t_pqueue *pqueue)
{
	int			parent;
	int			child;
	void		*content;
	t_pqnode	tmp;

	if (pqueue->size == 0)
		return (NULL);
	content = pqueue->heap[1].content;
	tmp = pqueue->heap[pqueue->size];
	pqueue->size--;
	parent = 1;
	child = 2;
	while (child <= pqueue->size)
	{
		if ((child < pqueue->size) && \
			(pqueue->heap[child].priority < pqueue->heap[child + 1].priority))
			child++;
		if (tmp.priority >= pqueue->heap[child].priority)
			break ;
		pqueue->heap[parent] = pqueue->heap[child];
		parent = child;
		child = child * 2;
	}
	pqueue->heap[parent] = tmp;
	return (content);
}
