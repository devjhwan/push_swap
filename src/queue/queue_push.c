/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:15:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 02:15:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	queue_push(t_queue *queue, void *content)
{
	t_queue_node	*new_node;
	t_queue_node	*last_node;

	new_node = queue_new_node(content);
	if (new_node == NULL)
		return (FAIL);
	if (queue->size == 0)
	{
		queue->list = new_node;
		queue->size++;
	}
	else
	{
		last_node = queue->list;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		queue->size++;
	}
	return (SUCCESS);
}
