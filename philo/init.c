/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:59:34 by tpoungla          #+#    #+#             */
/*   Updated: 2023/09/01 10:43:19 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initrule(t_rule *rule, char **tab)
{
	rule->no_of_philo = ft_atoi(tab[0]);
	rule->time_to_die = ft_atoi(tab[1]);
	rule->time_to_eat = ft_atoi(tab[2]);
	rule->time_to_sleep = ft_atoi(tab[3]);
	rule->state = 1;
	if (tab[4])
		rule->eat_times = ft_atoi(tab[4]);
	else
		rule->eat_times = -1;
}

t_philo	*ft_initphilo(t_rule *rule)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * rule->no_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < rule->no_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].right = i;
		philo[i].left = (i + 1) % rule->no_of_philo;
		philo[i].eaten = 0;
		philo[i].alive = 1;
		i++;
	}
	return (philo);
}

pthread_mutex_t	*ft_initfork(int no_of_philo)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = NULL;
	fork = malloc(sizeof(pthread_mutex_t) * no_of_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < no_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

int	ft_init(t_main *main, char **tab)
{
	ft_initrule(&main->rule, tab);
	main->philo = ft_initphilo(&main->rule);
	if (!main->philo)
		return (0);
	main->fork = ft_initfork(main->rule.no_of_philo);
	if (!main->fork)
		return (0);
	free_tab(tab);
	return (1);
}
