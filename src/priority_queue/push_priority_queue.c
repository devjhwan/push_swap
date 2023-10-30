/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_priority_queue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:50:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 02:50:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"

void	push_priority_queue(t_pqueue *pqueue, void *content, int priority)
{
	int			i;

	pqueue->size++;
	i = pqueue->size;
	while ((i > 1) && (priority > pqueue->heap[i / 2].priority))
	{
		pqueue->heap[i] = pqueue->heap[i / 2];
		i /= 2;
	}
	pqueue->heap[i].content = content;
	pqueue->heap[i].priority = priority;
}
