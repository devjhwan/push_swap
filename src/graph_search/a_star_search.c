/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:05:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/29 20:05:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "priority_queue.h"
#include "stack.h"
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

static t_node	*sort_node(t_node *node)
{
	t_node	*sorted_node;

	sorted_node = (t_node *)malloc(sizeof(t_node));
	if (sorted_node == NULL)
		return (NULL);
	sorted_node->stack_a = clone_stack(node->stack_a);
	if (sorted_node->stack_a == NULL)
		return (free(sorted_node), NULL);
	sort_stack(sorted_node->stack_a);
	if (reset_index_stack(node->stack_a, sorted_node->stack_a) == ERROR)
		return (free(sorted_node), free(sorted_node->stack_a), NULL);
	sorted_node->stack_b = clone_stack(node->stack_a);
	if (sorted_node->stack_a == NULL)
		return (free(sorted_node), free(sorted_node->stack_a), NULL);
	reverse_sort_stack(sorted_node->stack_b);
	sorted_node->adjacent_nodes = NULL;
	sorted_node->prev_node = NULL;
	sorted_node->last_action = NONE;
	return (sorted_node);
}

static int	calculate_heuristic(t_node *cur_node, t_node *sorted_node)
{
	(void)cur_node;
	(void)sorted_node;
	return (0);
}

static int	push_adjacent_nodes(t_pqueue *pqueue, t_node *cur_node)
{
	(void)pqueue;
	(void)cur_node;
	(void)calculate_heuristic;
	return (SUCCESS);
}

t_action	*a_star_search(t_node *start_node)
{
	t_pqueue	*pqueue;
	t_node		*cur_node;
	t_node		*sorted_node;
	char		*actions;

	pqueue = init_priority_queue();
	if (pqueue == NULL)
		return (NULL);
	sorted_node = sort_node(start_node);
	if (sorted_node == NULL)
		return (free_priority_queue(pqueue, NULL), NULL);
	push_priority_queue(pqueue, sorted_node, 0);
	cur_node = NULL;
	while (pqueue->size > 0)
	{
		cur_node = (t_node *)pop_priority_queue(pqueue);
		if (isnodesorted(cur_node))
			break ;
		if (push_adjacent_nodes(pqueue, cur_node) == ERROR)
			return (free_priority_queue(pqueue, NULL), NULL);
	}
	actions = get_sort_actions(cur_node);
	free_priority_queue(pqueue, NULL);
	return (actions);
}
