/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:34:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:34:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node *node)
{
	push(node->stack_b, node->stack_a);
}

void	pb(t_node *node)
{
	push(node->stack_a, node->stack_b);
}
