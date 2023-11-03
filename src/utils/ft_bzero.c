/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:52:08 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 04:53:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *arr, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)arr;
	if (size == 0)
		return ;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

