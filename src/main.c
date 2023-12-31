/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:41:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 20:41:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>

static char	*get_action_str(t_action action)
{
	if (action == PA)
		return ("pa\n");
	else if (action == PB)
		return ("pb\n");
	else if (action == SA)
		return ("sa\n");
	else if (action == SB)
		return ("sb\n");
	else if (action == SS)
		return ("ss\n");
	else if (action == RA)
		return ("ra\n");
	else if (action == RB)
		return ("rb\n");
	else if (action == RR)
		return ("rr\n");
	else if (action == RRA)
		return ("rra\n");
	else if (action == RRB)
		return ("rrb\n");
	else if (action == RRR)
		return ("rrr\n");
	else
		return ("Error\n");
}

static void	print_actions(t_action *actions)
{
	int	i;

	i = 1;
	while (actions[i] != '\0')
		i++;
	i--;
	while (actions[i] != '\0')
	{
		ft_putstr(get_action_str(actions[i]));
		i--;
	}
}

static void	sort_stack(t_node *node)
{
	t_action	*actions;

	actions = NULL;
	if (node->stack_a->size <= 5)
		actions = breadth_first_search(node);
	if (actions != NULL)
	{
		print_actions(actions);
		free(actions);
	}
}

int	main(int argc, char **argv)
{
	t_node		*node;

	if (argc < 2)
		return (0);
	node = init_node(argv);
	if (node == NULL)
		return (0);
	if (isnodesorted(node) == 0)
		sort_stack(node);
	free_node(node);
	return (0);
}
