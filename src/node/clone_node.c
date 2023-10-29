/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:20:50 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*clone_node(t_node *node, void (*act_function)(t_node *), \
					t_action action)
{
	t_node	*node_clone;

	node_clone = (t_node *)malloc(sizeof(t_node));
	if (node_clone == NULL)
		return (NULL);
	node_clone->stack_a = clone_stack(node->stack_a);
	node_clone->stack_b = clone_stack(node->stack_b);
	if (node_clone->stack_a == NULL || node_clone->stack_b == NULL)
		return (free_node(node_clone), NULL);
	act_function(node_clone);
	node_clone->adjacent_nodes = NULL;
	node_clone->prev_node = node;
	node_clone->last_action = action;
	return (node_clone);
}
