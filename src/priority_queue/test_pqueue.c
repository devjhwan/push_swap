/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:13:49 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 03:13:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"
#include <stdio.h>

int	main(void)
{
	t_pqueue	*pqueue;

	pqueue = init_priority_queue();
	if (pqueue == NULL)
		return (printf("Malloc error\n"));
	printf("--push--\n");
	push_priority_queue(pqueue, "1", 1);
	printf("1: %d\n", pqueue->heap[1].priority);
	push_priority_queue(pqueue, "10", 10);
	printf("2: %d\n", pqueue->heap[1].priority);
	push_priority_queue(pqueue, "6", 6);
	printf("3: %d\n", pqueue->heap[1].priority);
	push_priority_queue(pqueue, "9", 9);
	printf("4: %d\n", pqueue->heap[1].priority);
	push_priority_queue(pqueue, "20", 20);
	printf("5: %d\n", pqueue->heap[1].priority);
	printf("size: %d\n", pqueue->size);
	printf("\n--pop-\n");
	printf("1: %s\n", (char *)pop_priority_queue(pqueue));
	printf("2: %s\n", (char *)pop_priority_queue(pqueue));
	printf("3: %s\n", (char *)pop_priority_queue(pqueue));
	printf("4: %s\n", (char *)pop_priority_queue(pqueue));
	printf("5: %s\n", (char *)pop_priority_queue(pqueue));
	printf("size: %d\n", pqueue->size);
	free_priority_queue(pqueue, NULL);
	return (0);
}
