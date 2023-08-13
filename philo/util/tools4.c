/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:36:57 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/06 17:10:43 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isspace(char c)
{
	if (c == '\r' || c == '\n' || c == '\f' )
		return (1);
	else if (c == '\v' || c == '\t' || c == ' ' )
		return (1);
	return (0);
}

char	**arg_to_tab(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	**tab;
	char	*tmp;

	i = 2;
	str = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = tmp;
		i++;
	}
	tab = ft_split(str);
	free(str);
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = ' ';
	i++;
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (len--)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
