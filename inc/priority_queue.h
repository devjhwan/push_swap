/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:07:29 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/29 20:07:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIORITY_QUEUE_H
# define PRIORITY_QUEUE_H

# define INIT_SIZE 1000

typedef struct s_pqnode
{
	void	*content;
	int		priority;
}	t_pqnode;

typedef struct s_pqueue
{
	t_pqnode	*heap;
	int			size;
	int			maxsize;
}	t_pqueue;

t_pqueue	*init_priority_queue(void);
void		free_priority_queue(t_pqueue *pqueue, void (*delfunc)(void *));
int			push_priority_queue(t_pqueue *pqueue, void *content, int priority);
void		*pop_priority_queue(t_pqueue *pqueue);

#endif
