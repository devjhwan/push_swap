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

void	free_node(t_node **node, void (*del_func)(t_stack **))
{
	del_func(&((*node)->stack_a));
	del_func(&((*node)->stack_b));
	free(*node);
	*node = NULL;
}
