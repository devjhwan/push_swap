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

static double	calculate_cost(t_node *node, t_node *next_node)
{
	t_action	act;
	double		cost;

	act = next_node->last_action;
	if (act == SB || act == RB || act == RRB)
		cost = node->cost + 100;
	else if (act == RR || act == RRR || act == SS)
		cost = node->cost + 10;
	else if (act == RA || act == RRA)
		cost = node->cost + 2;
	else if (act == PA || act == PB || act == SA)
		cost = node->cost + 1;
	return (cost);
}

double	spearson(int *arr, int size)
{
	double	sum_d_square;
	double	result;
	int		tmp;
	int		i;

	i = 1;
	sum_d_square = 0;
	while (i <= size)
	{
		tmp = arr[i - 1] - i;
		sum_d_square += (double)(tmp * tmp);
		i++;
	}
	result = 1 - (6 * sum_d_square) / (size * (size * size - 1));
	if (result < 0)
		result *= -1;
	return (result);
}

static double	calculate_heuristic(t_node *node)
{
	double	spearson_corr;
	double	heuristic;
	int		count;

	count = 0;
	while (node->stack_b->cur_size > 0)
	{
		pa(node);
		count++;
	}
	spearson_corr = spearson(node->stack_a->arr, node->stack_a->size);
	heuristic = (1 - spearson_corr);
	heuristic *= 24.85 * node->stack_a->size;
	if (node->stack_a->size <= 100)
		heuristic *= 5;
	else
		heuristic *= 7;
	while (count > 0)
	{
		pb(node);
		count--;
		heuristic += 1;
	}
	return (heuristic);
}

static int	push_adjacent_nodes(t_pqueue *pqueue, t_node *cur_node)
{
	t_node	**adjacent_nodes;
	t_node	*adj_node;
	double	priority;
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
		adj_node->heuristic = calculate_heuristic(adj_node);
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
	char		*actions;

	pqueue = init_priority_queue();
	if (pqueue == NULL)
		return (NULL);
	if (assign_rank(start_node->stack_a) == ERROR)
		return (free_priority_queue(pqueue, NULL), NULL);
	if (push_priority_queue(pqueue, start_node, 0) == ERROR)
		return (free_priority_queue(pqueue, NULL), NULL);
	cur_node = (t_node *)pop_priority_queue(pqueue);
	while (!isnodesorted(cur_node))
	{
		if (push_adjacent_nodes(pqueue, cur_node) == ERROR)
			return (free_priority_queue(pqueue, NULL), NULL);
		cur_node = (t_node *)pop_priority_queue(pqueue);
	}
	actions = get_sort_actions(cur_node);
	free_priority_queue(pqueue, NULL);
	return (actions);
}
