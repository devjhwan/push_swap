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
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t newsize);
double	ft_log2(int x);

#endif
