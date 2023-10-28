/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:01:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct s_node
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_node;

t_node	*init_node(char **argv);
void	*parse_input(t_stack *stack_a, char **argv);
void	free_node(t_node **node, void (*del_func)(t_stack **));

#endif
