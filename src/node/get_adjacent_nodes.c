/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_adjacent_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:20:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

static int	find_push(t_node **adjacent_nodes, t_node *node, int *count)
{
	t_node *node_clone;

	if (node->stack_b->cur_size >= 1)
	{
		node_clone = clone_node(node, pa, PA);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_a->cur_size >= 1)
	{
		node_clone = clone_node(node, pb, PB);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	return (SUCCESS);
}

static int	find_swap(t_node **adjacent_nodes, t_node *node, int *count)
{
	t_node *node_clone;

	if (node->stack_a->cur_size >= 2)
	{
		node_clone = clone_node(node, sa, SA);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, sb, SB);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_a->cur_size >= 2 && node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, ss, SS);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	return (SUCCESS);
}

static int	find_rotate(t_node **adjacent_nodes, t_node *node, int *count)
{
	t_node *node_clone;

	if (node->stack_a->cur_size >= 2)
	{
		node_clone = clone_node(node, ra, RA);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, rb, RB);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_a->cur_size >= 2 && node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, rr, RR);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	return (SUCCESS);
}

static int	find_reverse_rotate(t_node **adjacent_nodes, \
								t_node *node, int *count)
{
	t_node *node_clone;

	if (node->stack_a->cur_size >= 2)
	{
		node_clone = clone_node(node, rra, RRA);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, rrb, RRB);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	if (node->stack_a->cur_size >= 2 && node->stack_b->cur_size >= 2)
	{
		node_clone = clone_node(node, rrr, RRR);
		if (node_clone == NULL)
			return (ERROR);
		adjacent_nodes[(*count)++] = node_clone;
	}
	return (SUCCESS);
}

t_node	**get_adjacent_nodes(t_node *node)
{
	t_node	**adjacent_nodes;
	int		count;

	adjacent_nodes = (t_node **)malloc(sizeof(t_node *) * 12);
	if (adjacent_nodes == NULL)
		return (NULL);
	count = 0;
	if (find_push(adjacent_nodes, node, &count) == ERROR || \
		find_swap(adjacent_nodes, node, &count) == ERROR || \
		find_rotate(adjacent_nodes, node, &count) == ERROR || \
		find_reverse_rotate(adjacent_nodes, node, &count) == ERROR)
	{
		count = 0;
		while (adjacent_nodes[count] != NULL)
			free_node(adjacent_nodes[count++]);
		free(adjacent_nodes);
		return (NULL);
	}
	return (adjacent_nodes);
}
