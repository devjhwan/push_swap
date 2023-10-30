/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_priority_queue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:32:53 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 02:32:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"
#include <stdlib.h>

void	free_priority_queue(t_pqueue *pqueue, void (*delfunc)(void *))
{
	int		i;

	if (pqueue->heap != NULL)
	{
		if (delfunc != NULL)
		{
			i = 1;
			while (i < pqueue->size)
			{
				delfunc(pqueue->heap[i].content);
				pqueue->heap[i].content = NULL;
				i++;
			}
		}
		free(pqueue->heap);
		pqueue->heap = NULL;
	}
	free(pqueue);
}
