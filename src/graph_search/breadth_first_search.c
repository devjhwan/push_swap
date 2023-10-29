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

#define SUCCESS 0
#define ERROR 1

int	push_adjacent_nodes(t_queue *queue, t_node *cur_node)
{
	t_node	**adjacent_nodes;
	int		i;

	adjacent_nodes = get_adjacent_nodes(cur_node);
	if (adjacent_nodes == NULL)
		return (ERROR);
	cur_node->adjacent_nodes = adjacent_nodes;
	i = 0;
	while (adjacent_nodes[i] != NULL)
	{
		if (push_queue(queue, adjacent_nodes[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

t_node	*find_sorted_node(t_node *cur_node)
{
	t_node	**adj_nodes;
	int		i;

	adj_nodes = cur_node->adjacent_nodes;
	i = 0;
	while (adj_nodes[i] != NULL)
	{
		if (isnodesorted(adj_nodes[i]))
			return (adj_nodes[i]);
		i++;
	}
	return (NULL);
}

t_action	*get_sort_actions(t_node *sorted_node)
{
	t_action	*actions;
	t_node		*cur_node;
	int			i;

	actions = (t_action *)malloc(sizeof(t_action) * \
									sorted_node->stack_a->size * 10);
	if (actions == NULL)
		return (NULL);
	cur_node = sorted_node;
	i = 1;
	actions[0] = '\0';
	while (cur_node->last_action != NONE)
	{
		actions[i] = cur_node->last_action;
		cur_node = cur_node->prev_node;
		i++;
	}
	actions[i] = '\0';
	return (actions);
}

t_action	*breadth_first_search(t_node *start_node)
{
	t_queue	*queue;
	t_node	*cur_node;
	t_node	*sorted_node;
	char	*actions;

	queue = init_queue();
	if (queue == NULL)
		return (NULL);
	if (push_queue(queue, start_node) == 1)
		return (free_queue(queue, NULL), NULL);
	sorted_node = NULL;
	actions = NULL;
	while (queue->size > 0 && sorted_node == NULL)
	{
		cur_node = (t_node *)pop_queue(queue);
		if (push_adjacent_nodes(queue, cur_node) == ERROR)
			return (free_queue(queue, NULL), NULL);
		sorted_node = find_sorted_node(cur_node);
	}
	actions = get_sort_actions(sorted_node);
	free_queue(queue, NULL);
	return (actions);
}
