/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 15:46:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	free_queue(t_queue *queue, void (*del_func)(void *))
{
	void	*del_content;

	while (queue->size > 0)
	{
		del_content = pop_queue(queue);
		if (del_func != NULL)
			del_func(del_content);
	}
	free(queue);
}
