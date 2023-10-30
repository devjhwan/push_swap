/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_priority_queue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:24:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 02:24:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"
#include <stdlib.h>

t_pqueue	*init_priority_queue(void)
{
	t_pqueue	*pqueue;

	pqueue = (t_pqueue *)malloc(sizeof(t_pqueue));
	if (pqueue == NULL)
		return (NULL);
	pqueue->size = 0;
	pqueue->maxsize = INIT_SIZE;
	pqueue->heap = (t_pqnode *)malloc(sizeof(t_pqnode) * (INIT_SIZE + 1));
	if (pqueue->heap == NULL)
		return (free_priority_queue(pqueue), NULL);
	return (pqueue);
}
