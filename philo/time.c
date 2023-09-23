/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:37:45 by tpoungla          #+#    #+#             */
/*   Updated: 2023/09/23 11:46:28 by tpoungla         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = main->no_philo;
	main->philo[i].start_meal = main->philo[i].start_time;
	while (main->rule.state)
	{
		philo_eat1(&main->philo[i], main->fork, main);
		philo_eat2(&main->philo[i], main->fork, main);
		sleep_think(&main->philo[i], main);
	}
	return (NULL);
}
