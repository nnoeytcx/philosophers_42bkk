/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:26:39 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/05 23:47:38 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_get_str(char const *s, char **res)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	m = 0;
	n = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && s[i])
		{
			res[m][n] = s[i];
			n++;
		}
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
		{
			res[m][n] = '\0';
			m++;
			n = 0;
		}
		i++;
	}
	res[m] = NULL;
}

void	ft_get_tab(char const *s, char **res)
{
	int	i;
	int	m;
	int	n;

	n = 0;
	m = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && s[i])
			n++;
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
		{
			res[m] = malloc(sizeof(char) * (n + 1));
			if (!res[m])
			{
				while (res[m])
					free(res[m--]);
			}
			m++;
			n = 0;
		}
		i++;
	}
}

char	**ft_split(char *s)
{
	int		i;
	int		co;
	char	**res;

	co = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || s[i + 1] == '\0'))
			co++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (co + 1));
	if (!res)
		return (NULL);
	ft_get_tab(s, res);
	ft_get_str(s, res);
	return (res);
}

int	valid_lst_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!valid_str(tab[i]))
		{
			return (0);
		}
		if (ft_atoi(tab[i]) != ft_atol(tab[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
