/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taylor_series.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:46:23 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/05 23:46:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define MAX_LOG 5000
#define	REP 2000

static double	taylor_series(double x)
{
	double	coefficient;
	double	result;
	int		i;

	result = 0;
	i = REP;
	while (i >= 1)
	{
		coefficient = x / i;
		if (i % 2 == 0)
			coefficient *= -1;
		result = result * x + coefficient;
		i--;
	}
	return (result);
}

double	ft_log2(int x)
{
	static double	log_2[MAX_LOG];
	static double	ln_2;

	if (x <= 1)
		return (0);
	if (ln_2 == 0)
		ln_2 = taylor_series(1);
	if (log_2[x] == 0)
		log_2[x] = -(taylor_series(1 / (double)x - 1) / ln_2);
	return (log_2[x]);
}
