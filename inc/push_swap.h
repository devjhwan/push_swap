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
# include "hash.h"

typedef char	t_action;

# define NONE 0
# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_node
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	struct s_node	**adjacent_nodes;
	struct s_node	*prev_node;
	t_action		last_action;
	double			cost;
	double			heuristic;
}	t_node;

void			*parse_input(t_stack *stack_a, char **argv);
t_node			*init_node(char **argv);
void			free_node(void *node);
int				isnodesorted(t_node *node);
t_node			*clone_node(t_node *node, void (*act_function)(t_node *), \
							t_action action);
t_node			**get_adjacent_nodes(t_node *node);
t_node			*find_sorted_node(t_node **nodes);
t_action		*get_sort_actions(t_node *sorted_node);
unsigned int	get_hash_key(t_node *node);
int				isequal_node(void *n1, void *n2);

t_action		*breadth_first_search(t_node *start_node, t_hash **hash);
t_action		*a_star_search(t_node *start_node);

void			pa(t_node *node);
void			pb(t_node *node);
void			sa(t_node *node);
void			sb(t_node *node);
void			ss(t_node *node);
void			ra(t_node *node);
void			rb(t_node *node);
void			rr(t_node *node);
void			rra(t_node *node);
void			rrb(t_node *node);
void			rrr(t_node *node);

#endif
