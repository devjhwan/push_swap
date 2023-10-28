/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:16:13 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 02:16:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

# define SUCCESS 0
# define FAIL 1

typedef struct s_queue_node
{
	void				*content;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*list;
	int				size;
}	t_queue;

t_queue			*init_queue(void);
int				push_queue(t_queue *queue, void *content);
void			*pop_queue(t_queue *queue);
void			free_queue(t_queue **queue, void (*del_func)(void *));

#endif
