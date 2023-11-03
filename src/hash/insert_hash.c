/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:15:49 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 05:15:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

#define SUCCESS 0
#define ERROR 1

int	insert_hash(t_hash **hash, const unsigned int key, const void *value)
{
	t_hash	*newnode;
	t_hash	*curnode;

	newnode = (t_hash *)malloc(sizeof(t_hash));
	if (newnode == NULL)
		return (ERROR);
	newnode->content = (void *)value;
	newnode->next = NULL;
	if (hash[key] == NULL)
		hash[key] = newnode;
	else
	{
		curnode = hash[key];
		while (curnode->next != NULL)
			curnode = curnode->next;
		curnode->next = newnode;
	}
	return (SUCCESS);
}
