/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:47:41 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/07 15:37:26 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->rule.no_of_philo)
	{
		pthread_mutex_destroy(&main->fork[i]);
		i++;
	}
	free(main->philo);
	free(main->fork);
	main->philo = NULL;
	main->fork = NULL;
}

int	check_eat(t_main *main)
{
	int	i;

	i = 0;
	if (main->rule.eat_times == -1)
		return (0);
	while (i < main->rule.no_of_philo)
	{
		if (main->philo[i].eaten < main->rule.eat_times)
			return (0);
		i++;
	}
	return (1);
}

int	check_die(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->rule.no_of_philo)
	{
		if (time_diff(main->philo[i].stmeal) > \
		main->rule.time_to_die)
		{
			main->philo[i].alive = 0;
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**tab;
	t_main	main;
	int		i;

	i = 0;
	tab = check_args(argc, argv);
	if (!tab)
		return (0);
	ft_init(&main, tab);
	ft_strtheard(&main);
	while (main.rule.state)
	{
		if (main.rule.eat_times != -1 && check_eat(&main))
			break ;
		if (check_die(&main) != 0)
		{
			printf(DIE, GRAY, get_ms() - main.rule.start_time, i + 1);
			break ;
		}
		usleep(10);
		i++;
		i = i % main.rule.no_of_philo;
	}
	free_philo(&main);
}
