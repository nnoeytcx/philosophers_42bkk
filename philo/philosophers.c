/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:47:41 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/11 14:33:10 by tpoungla         ###   ########.fr       */
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

	tab = check_args(argc, argv);
	if (!tab)
		return (0);
	if (ft_atoi(tab[0]) == 0 || (tab[4] && ft_atoi(tab[4]) == 0) \
	|| ft_atoi(tab[2]) == 0 || ft_atoi(tab[3]) == 0)
	{
		printf(ERR);
		printf(INVL_ARG);
		free_tab(tab);
		return (0);
	}
	else
		ft_init(&main, tab);
	ft_strtheard(&main);
	threading(&main);
	free_philo(&main);
}
