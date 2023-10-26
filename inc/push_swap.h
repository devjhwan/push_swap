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

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	first;
	int	last;
	int	cur_size;
}	t_stack;

int		ft_putstr(char *str);
int		print_stack(t_stack *stack);
void	*parse_input(t_stack **stack_a, char **argv);
t_stack	*init_stack(int size);
void	free_stack(t_stack *stack);

#endif
