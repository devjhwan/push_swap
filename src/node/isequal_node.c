/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isequal_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:59 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 12:05:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isequal_node(void *n1, void *n2)
{
	t_node	*node1;
	t_node	*node2;
	int	i;

	node1 = (t_node *)n1;
	node2 = (t_node *)n2;
	if (node1->stack_a->cur_size != node2->stack_a->cur_size)
		return (0);
	if (node1->stack_b->cur_size != node2->stack_b->cur_size)
		return (0);
	i = 0;
	while (i < node1->stack_a->cur_size)
	{
		if (node1->stack_a->arr[i] != node2->stack_a->arr[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < node1->stack_b->cur_size)
	{
		if (node1->stack_b->arr[i] != node2->stack_b->arr[i])
			return (0);
		i++;
	}
	return (1);
}
