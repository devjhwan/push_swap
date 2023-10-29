/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:20:18 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/28 16:20:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>

static int	count_arguments(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			else if (argv[i][j] != ' ')
			{
				count++;
				while (argv[i][j] != ' ' && argv[i][j] != '\0')
					j++;
			}
		}
		i++;
	}
	return (count);
}

t_node	*init_node(char **argv)
{
	t_node	*node;
	int		size;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	size = count_arguments(argv);
	node->stack_a = init_stack(size);
	node->stack_b = init_stack(size);
	node->adjacent_nodes = NULL;
	node->prev_node = NULL;
	node->last_action = NONE;
	if (node->stack_a == NULL || node->stack_b == NULL)
		return (free_node(node), NULL);
	if (parse_input(node->stack_a, argv) == NULL)
	{
		ft_putstr("Error\n");
		return (free_node(node), NULL);
	}
	return (node);
}
