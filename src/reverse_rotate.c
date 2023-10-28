/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:40:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:40:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node *node)
{
	reverse_rotate_stack(node->stack_a);
}

void	rrb(t_node *node)
{
	reverse_rotate_stack(node->stack_b);
}

void	rrr(t_node *node)
{
	reverse_rotate_stack(node->stack_a);
	reverse_rotate_stack(node->stack_b);
}
