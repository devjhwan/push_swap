/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:21:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 15:21:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_pop(t_queue *queue)
{
	t_queue_node	*delnode;
	void			*content;

	if (queue->size == 0)
		return (NULL);
	delnode = queue->list;
	queue->list = queue->list->next;
	content = delnode->content;
	delnode->next = NULL;
	free(delnode);
	return (content);
}
