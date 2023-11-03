/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:46:33 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 04:46:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>

typedef struct s_hash
{
	void			*content;
	struct s_hash	*next;
}	t_hash;

# define HASH_SIZE 10000000

t_hash	**init_hash(void);
void	free_hash(t_hash **hash, void (*delfunc)(void *));
int		insert_hash(t_hash **hash, const unsigned int key, const void *value);
int		check_hash(t_hash **hash, const unsigned int key, const void *value, \
					int (*isequal)(void *, void *));

#endif