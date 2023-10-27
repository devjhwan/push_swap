/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:09:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/27 22:09:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define INT_MIN -2147483648

int	ft_putchar(int ch)
{
	return (write(1, &ch, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}

int	ft_putnbr(int num)
{
	if (num == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		num *= -1;
	}
	if (num > 9)
		if (ft_putnbr(num / 10) < 0)
			return (-1);
	return (ft_putchar(num % 10 + '0'));
}