/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:22:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:22:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_node(void *node)
{
	t_node	*delnode;
	int		i;

	delnode = (t_node *)node;
	if (delnode->adjacent_nodes != NULL)
	{
		i = 0;
		while (delnode->adjacent_nodes[i] != NULL)
			free_node(delnode->adjacent_nodes[i++]);
		free(delnode->adjacent_nodes);
		delnode->adjacent_nodes = NULL;
	}
	free_stack(delnode->stack_a);
	free_stack(delnode->stack_b);
	delnode->stack_a = NULL;
	delnode->stack_b = NULL;
	free(delnode);
}
