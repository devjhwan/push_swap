/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:30:08 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 15:30:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	del_func(void *content)
{
	(void)content;
}

int main(void)
{
	t_queue	*queue;
	char	*test;

	queue = init_queue();
	printf("queue_pointer: %p\n", queue);
	if (push_queue(queue, "hola") != 0)
	{
		free(queue);
		return (1);
	}
	printf("queue size: %d\n", queue->size);
	test = pop_queue(queue);
	printf("%s\n", test);
	printf("queue size: %d\n", queue->size);
	test = pop_queue(queue);
	if (test != NULL)
	{
		printf("Empty queue pop error\n");
		return (0);
	}
	if (push_queue(queue, "hola") != 0)
	{
		free(queue);
		return (1);
	}
	if (push_queue(queue, "hola1") != 0)
	{
		free(queue);
		return (1);
	}
	if (push_queue(queue, "hola2") != 0)
	{
		free(queue);
		return (1);
	}
	printf("queue size: %d\n", queue->size);
	free_queue(&queue, del_func);
	printf("queue_pointer: %p\n", queue);
	printf("All complete\n");
	return (0);
}
