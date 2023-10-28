/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:32:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:32:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "queue.h"

void	push_adjacent_nodes(t_queue *queue, t_node *cur_node)
{
	return ;
}

char	*breadth_first_search(t_node *start_node)
{
	t_queue	*queue;
	t_node	*cur_node;

	queue = init_queue();
	if (queue == NULL)
		return (NULL);
	if (push_queue(queue, start_node) == 1)
		return (free_queue(queue, free_node), NULL);
	while (queue->size > 0)
	{
		cur_node = (t_node *)pop_queue(queue);
		push_adjacent_nodes(queue, cur_node);
	}
	free_queue(queue, free_node);
	(void)cur_node;
	return (NULL);
}
