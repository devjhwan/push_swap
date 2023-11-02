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
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

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

static int	calculate_cost(t_node *node, t_node *next_node)
{
	t_action	act;
	int			cost;

	act = next_node->last_action;
	if (act == SB || act == RB || act == RRB)
		cost = node->cost + 10000;
	else if (act == RR || act == RRR || act == SS)
		cost = node->cost + 100;
	else if (act == RA || act == RRA)
		cost = node->cost + 11;
	else if (act == PA || act == PB || act == SA)
		cost = node->cost + 10;
	return (cost);
}

static int	calculate_heuristic(t_node *node, t_node *sorted_node)
{
	(void)node;
	(void)sorted_node;
	return (0);
}

static int	push_adjacent_nodes(t_pqueue *pqueue, t_node *cur_node, \
								t_node *sorted_node)
{
	t_node	**adjacent_nodes;
	t_node	*adj_node;
	int		priority;
	int		i;

	adjacent_nodes = get_adjacent_nodes(cur_node);
	if (adjacent_nodes == NULL)
		return (ERROR);
	cur_node->adjacent_nodes = adjacent_nodes;
	i = 0;
	while (adjacent_nodes[i] != NULL)
	{
		adj_node = adjacent_nodes[i];
		adj_node->cost = calculate_cost(cur_node, adj_node);
		adj_node->heuristic = calculate_heuristic(adj_node, sorted_node);
		priority = adj_node->cost + adj_node->heuristic;
		if (push_priority_queue(pqueue, adj_node, priority) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

t_action	*a_star_search(t_node *start_node)
{
	t_pqueue	*pqueue;
	t_node		*cur_node;
	t_node		*sorted_node;
	char		*actions;
	int			debug;

	pqueue = init_priority_queue();
	if (pqueue == NULL)
		return (NULL);
	sorted_node = sort_node(start_node);
	if (sorted_node == NULL)
		return (free_priority_queue(pqueue, NULL), NULL);
	if (push_priority_queue(pqueue, start_node, 0) == ERROR)
		return (free_priority_queue(pqueue, NULL), free(sorted_node), NULL);
	cur_node = (t_node *)pop_priority_queue(pqueue);
	while (!isnodesorted(cur_node))
	{
		print_stack(cur_node->stack_a);
		print_stack(cur_node->stack_b);
		ft_putstr("cost = ");
		ft_putnbr(cur_node->cost);
		ft_putchar('\n');
		ft_putstr("heuristic = ");
		ft_putnbr(cur_node->heuristic);
		ft_putchar('\n');
		(void)debug;
		if (push_adjacent_nodes(pqueue, cur_node, sorted_node) == ERROR)
			return (free_priority_queue(pqueue, NULL), \
					free(sorted_node), NULL);
		cur_node = (t_node *)pop_priority_queue(pqueue);
	}
	actions = get_sort_actions(cur_node);
	free_priority_queue(pqueue, NULL);
	free(sorted_node);
	return (actions);
}
