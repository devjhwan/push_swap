/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:23:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/30 03:23:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	char	*new_ptr;
	char	*old_ptr;
	size_t	i;

	if (size == 0)
		return (free(ptr), NULL);
	new_ptr = (char *)malloc(sizeof(char) * size);
	if (new_ptr == NULL || ptr == NULL)
		return (free(ptr), free(new_ptr), NULL);
	i = 0;
	old_ptr = (char *)ptr;
	while (i < old_size)
	{
		new_ptr[i] = old_ptr[i];
		i++;
	}
	free(ptr);
	return ((void *)new_ptr);
}
