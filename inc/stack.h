/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:06:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/27 22:06:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	*arr;
	int	first;
	int	last;
	int	size;
	int	cur_size;
}	t_stack;

t_stack	*init_stack(int size);
int		print_stack(t_stack *stack);
void	free_stack(t_stack **stack);

void	push_stack(t_stack *origin, t_stack *dest);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif
