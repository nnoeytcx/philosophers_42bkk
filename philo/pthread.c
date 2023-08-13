/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:44:02 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/11 04:57:37 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo, t_main *main)
{
	printf(SLEEP, CYAN, get_ms() - main->rule.start_time, philo->id);
	time_to_action(main->rule.time_to_sleep);
	printf(THK, GREEN, get_ms() - main->rule.start_time, philo->id);
}

void	philo_eat(t_philo *philo, pthread_mutex_t *fork, t_main *main)
{
	pthread_mutex_lock(&fork[philo->right]);
	printf(FRK, MAGENTA, get_ms() - main->rule.start_time, philo->id);
	pthread_mutex_lock(&fork[philo->left]);
	printf(FRK, MAGENTA, get_ms() - main->rule.start_time, philo->id);
	printf(EAT, YELLOW, get_ms() - main->rule.start_time, philo->id);
	philo->eaten++;
	philo->stmeal = get_ms();
	time_to_action(main->rule.time_to_eat);
	pthread_mutex_unlock(&fork[philo->right]);
	pthread_mutex_unlock(&fork[philo->left]);
}

void	*routine(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = main->no_philo;
	main->philo[i].stmeal = main->rule.start_time;
	while (main->rule.state)
	{
		philo_eat(&main->philo[i], main->fork, main);
		sleep_think(&main->philo[i], main);
	}
	return (NULL);
}

int	ft_strtheard(t_main *main)
{
	int	i;

	i = 0;
	main->rule.start_time = get_ms();
	while (i < main->rule.no_of_philo)
	{
		main->no_philo = i;
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
			break ;
		if (check_die(main) != 0)
		{
			printf(DIE, GRAY, get_ms() - main->rule.start_time, i + 1);
			break ;
		}
		usleep(10);
		i++;
		i = i % main->rule.no_of_philo;
	}
}
