/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:38:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *node)
{
	swap(node->stack_a);
}

void	sb(t_node *node)
{
	swap(node->stack_b);
}

void	ss(t_node *node)
{
	swap(node->stack_a);
	swap(node->stack_b);
}
