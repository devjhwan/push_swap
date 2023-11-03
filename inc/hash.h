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

typedef struct s_hash
{
	void			*content;
	struct s_hash	*next;
}	t_hash;

# define HASH_SIZE 1000000

#endif
