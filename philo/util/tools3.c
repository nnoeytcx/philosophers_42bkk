/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:43:21 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/05 23:47:41 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	valid_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ((i == 0)
				&& (str[i] == '+')
				&& ft_strlen(str) != 1))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_isdigit(int arg)
{
	if (arg < '0' || arg > '9')
		return (0);
	return (1);
}

int	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 4 && i != 5)
	{
		printf(ERR);
		printf(WRG_NUM_ARG);
		return (0);
	}
	i = 0;
	while (tab[i])
	{
		if (!valid_str(tab[i]) || (ft_atoi(tab[i]) != ft_atol(tab[i])))
		{
			printf(ERR);
			printf(INVL_ARG);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**check_args(int argc, char *argv[])
{
	int		i;
	char	**tab;

	i = 0;
	if (argc == 1)
	{
		printf(ERR);
		printf(WRG_NUM_ARG);
		return (NULL);
	}
	else if (argc == 2)
		tab = ft_split(argv[1]);
	else
		tab = arg_to_tab(argc, argv);
	if (!check_tab(tab))
	{
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
