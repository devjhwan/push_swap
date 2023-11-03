/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:27:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/03 05:27:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*ft_strcat(char *str1, const char *str2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str1);
	j = 0;
	while (str2[j] != '\0')
		str1[i++] = str2[j++];
	str1[i] = '\0';
	return (str1);
}
