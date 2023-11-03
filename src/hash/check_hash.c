/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:15:56 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 05:15:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

int	check_hash(t_hash **hash, const unsigned int key, const void *value, \
				int (*isequal)(void *, void *))
{
	t_hash	*curnode;

	curnode = hash[key];
	while (curnode != NULL)
	{
		if (isequal(curnode->content, (void *)value))
			return (1);
		curnode = curnode->next;
	}
	return (0);
}
