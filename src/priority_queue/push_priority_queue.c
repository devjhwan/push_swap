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
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define ERROR 1

int	push_priority_queue(t_pqueue *pqueue, void *content, int priority)
{
	int	i;
	//int	debug;

	pqueue->size++;
	if (pqueue->size > pqueue->maxsize)
	{
		pqueue->heap = ft_realloc(pqueue->heap, \
							sizeof(t_pqnode) * (pqueue->maxsize * 1.2+ 1), \
							sizeof(t_pqnode) * pqueue->maxsize);
		pqueue->maxsize *= 1.2;
		if (pqueue->heap == NULL)
			return (ERROR);
	}
	i = pqueue->size;
	while ((i > 1) && (priority < pqueue->heap[i / 2].priority))
	{
		pqueue->heap[i] = pqueue->heap[i / 2];
		i /= 2;
	}
	pqueue->heap[i].content = content;
	pqueue->heap[i].priority = priority;
	return (SUCCESS);
}
