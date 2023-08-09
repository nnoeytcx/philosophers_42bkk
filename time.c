/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:37:45 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/06 22:32:17 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ms(void)
{
	t_timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	time_diff(long time)
{
	return (get_ms() - time);
}

void	time_to_action(long time_action)
{
	long	start;
	long	dif;

	start = get_ms();
	dif = 0;
	while (dif < time_action)
	{
		dif = time_diff(start);
		usleep(50);
	}
}
