/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:55:31 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 04:55:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	free_hash(t_hash **hash, void (*delfunc)(void *))
{
	t_hash	*delhash;
	t_hash	*tmp;
	int		i;

	i = 0;
	while (i < HASH_SIZE)
	{
		tmp = hash[i];
		while (tmp != NULL)
		{
			delhash = tmp;
			tmp = tmp->next;
			if (delfunc != NULL)
				delfunc(delhash->content);
			free(delhash);
		}
		i++;
	}
	free(hash);
}
