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

static void	sort_stack(t_node *node)
{
	char	*actions;

	actions = NULL;
	if (node->stack_a->size <= 5)
		actions = breadth_first_search(node);
	if (actions != NULL)
	{
		ft_putstr(actions);
		free(actions);
	}
}

#include <stdio.h>

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
