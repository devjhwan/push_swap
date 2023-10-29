/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:53:48 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/29 19:53:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
