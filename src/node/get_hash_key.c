/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:44:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 05:44:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "hash.h"

#define HASH_PRIME1 31
#define HASH_PRIME2	37

unsigned int	get_hash_key(t_node *node)
{
	unsigned int	hashkey;
	int				i;

	hashkey = 0;
	i = 0;
	while (i < node->stack_a->cur_size)
	{
		hashkey = (hashkey * HASH_PRIME1) + node->stack_a->arr[i];
		i++;
	}
	i = 0;
	while (i < node->stack_b->cur_size)
	{
		hashkey = (hashkey * HASH_PRIME2) + node->stack_b->arr[i];
		i++;
	}
	hashkey %= HASH_SIZE;
	return (hashkey);
}
