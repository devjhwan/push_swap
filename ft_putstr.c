/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:40:28 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/26 21:40:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
