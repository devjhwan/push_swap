/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:39:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:39:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node *node)
{
	rotate(node->stack_a);
}

void	rb(t_node *node)
{
	rotate(node->stack_b);
}

void	rr(t_node *node)
{
	rotate(node->stack_a);
	rotate(node->stack_b);
}
