/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:46:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 04:46:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "utils.h"
#include <stdlib.h>

t_hash	**init_hash(void)
{
	t_hash	**hash;

	hash = (t_hash **)ft_calloc(1000000, sizeof(t_hash *));
	if (hash == NULL)
		return (NULL);
	return (hash);
}
