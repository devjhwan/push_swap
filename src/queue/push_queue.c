/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:15:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 02:15:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static t_queue_node	*new_node_queue(void *content)
{
	t_queue_node	*node;

	node = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	push_queue(t_queue *queue, void *content)
{
	t_queue_node	*new_node;
	t_queue_node	*last_node;

	new_node = new_node_queue(content);
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
