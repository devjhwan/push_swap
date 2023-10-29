/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sorted_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:52:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/29 19:52:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*find_sorted_node(t_node **nodes)
{
	int		i;

	i = 0;
	while (nodes[i] != NULL)
	{
		if (isnodesorted(nodes[i]))
			return (nodes[i]);
		i++;
	}
	return (NULL);
}
