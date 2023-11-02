/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:10:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/10/27 22:10:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		ft_putchar(int ch);
int		ft_putstr(char *str);
int		ft_putnbr(int num);
void	*ft_realloc(void *ptr, size_t size, size_t old_size);
int		ft_pow(int nb, int exp);
int		ft_abs(int nb);

#endif
