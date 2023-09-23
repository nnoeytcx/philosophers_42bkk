/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:44:02 by tpoungla          #+#    #+#             */
/*   Updated: 2023/09/23 11:46:33 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo, t_main *main)
{
	if (!main->rule.state)
		return ;
	printf(SLEEP, CYAN, time_diff(philo->start_time), philo->id);
	if (!main->rule.state)
		return ;
	time_to_action(main->rule.time_to_sleep);
	if (!main->rule.state)
		return ;
	printf(THK, GREEN, time_diff(philo->start_time), philo->id);
}

void	philo_eat1(t_philo *philo, pthread_mutex_t *fork, t_main *main)
{
	if (!main->rule.state)
		return ;
	pthread_mutex_lock(&fork[philo->right]);
	if (!main->rule.state)
		return ;
	printf(FRK, MAGENTA, time_diff(philo->start_time), philo->id);
	if (!main->rule.state)
		return ;
	pthread_mutex_lock(&fork[philo->left]);
	if (!main->rule.state)
		return ;
	printf(FRK, MAGENTA, time_diff(philo->start_time), philo->id);
	if (!main->rule.state)
		return ;
	printf(EAT, YELLOW, time_diff(philo->start_time), philo->id);
}

void	philo_eat2(t_philo *philo, pthread_mutex_t *fork, t_main *main)
{
	if (!main->rule.state)
		return ;
	philo->eaten++;
	if (!main->rule.state)
		return ;
	philo->start_meal = get_ms();
	if (!main->rule.state)
		return ;
	time_to_action(main->rule.time_to_eat);
	if (!main->rule.state)
		return ;
	pthread_mutex_unlock(&fork[philo->right]);
	if (!main->rule.state)
		return ;
	pthread_mutex_unlock(&fork[philo->left]);
}

int	ft_strtheard(t_main *main)
{
	int		i;
	long	time;

	i = 0;
	time = get_ms();
	while (i < main->rule.no_of_philo)
	{
		main->no_philo = i;
		main->philo[i].start_time = time;
		if (pthread_create(&main->philo[i].th, NULL, &routine, main))
			return (0);
		if (pthread_detach(main->philo[i].th))
			return (0);
		usleep(10);
		i += 2;
		if (i >= main->rule.no_of_philo && i % 2 == 0)
		{
			usleep (50);
			i = 1;
		}
	}
	return (1);
}

void	threading(t_main *main)
{
	int		i;

	i = 0;
	while (main->rule.state)
	{
		if (main->rule.eat_times != -1 && check_eat(main))
		{
			main->rule.state = 0;
			return ;
		}
		if (check_die(main, i) != 0)
		{
			printf(DIE, GRAY, get_ms() - main->philo[i].start_time, i + 1);
			main->rule.state = 0;
			return ;
		}
		i++;
		i = i % main->rule.no_of_philo;
	}
}
