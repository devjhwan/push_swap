/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_visualizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:11:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 23:11:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

#define ERROR 0
#define SUCCESSFUL 1

int	print_stack(t_stack *stack)
{
	int	i;
	int	count;

	i = stack->first;
	count = 0;
	if (ft_putstr("-----STACK-----\n") < 0)
		return (ERROR);
	while (count < stack->cur_size)
	{
		if (ft_putstr("  ") < 0)
			return (ERROR);
		if (ft_putnbr(stack->arr[i]) < 0)
			return (ERROR);
		if (ft_putchar('\n') < 0)
			return (ERROR);
		i = (i + 1) % stack->size;
		count++;
	}
	return (SUCCESSFUL);
}
