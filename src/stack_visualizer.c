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

#include "push_swap.h"
#include <unistd.h>

#define ERROR 0
#define SUCCESSFUL 1

int	ft_putchar(int ch)
{
	return (write(1, &ch, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}

int	ft_putnbr(int num)
{
	int		res;

	res = 0;
	if (num > 9)
		res = ft_putnbr(num / 10);
	if (res < 0)
		return (-1);
	if (ft_putchar(num % 10 + '0') < 0)
		return (-1);
	return (res + 1);
}

int	print_stack(t_stack *stack)
{
	int	i;
	int count;

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
