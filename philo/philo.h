/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:47:47 by tpoungla          #+#    #+#             */
/*   Updated: 2023/08/31 21:12:08 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval	t_timeval;
typedef struct s_rule
{
	int		no_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		eat_times;
	int		state;
}	t_rule;
typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				left;
	int				right;
	int				eaten;
	int				alive;
	long			start_meal;
	long			start_time;
}	t_philo;
typedef struct s_main
{
	t_rule			rule;
	t_philo			*philo;
	int				no_philo;
	pthread_mutex_t	*fork;
}	t_main;

# define BLK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"

# define THK		"%s%ld %d is thinking\n"
# define FRK		"%s%ld %d has taken a fork\n"
# define EAT		"%s%ld %d is eating\n"
# define SLEEP		"%s%ld %d is sleeping\n"
# define DIE		"%s%ld %d died\n"

# define ERR "Error : "
# define INVL_ARG "invalid arguments\n"
# define WRG_NUM_ARG "wrong number of arguments\n"

int				check_eat(t_main *main, int i);
int				check_die(t_main *main, int i);

//tools1.c
int				ft_strlen(const char *s);
void			ft_get_str(char const *s, char **res);
void			ft_get_tab(char const *s, char **res);
char			**ft_split(char *s);
int				valid_lst_tab(char **tab);

//tool2.c
int				get_num(const char *str, int i);
int				check_space(const char *c, int i);
int				ft_atoi(const char *str);
long			get_longnum(const char *str, int i);
long			ft_atol(const char *str);

//tools3.c
int				valid_str(char *str);
int				ft_isdigit(int arg);
int				check_tab(char **tab);
char			**check_args(int argc, char *argv[]);
void			free_tab(char **tab);

//tools4.c
int				ft_isspace(char c);
char			**arg_to_tab(int argc, char *argv[]);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char *s2);

//init.c
void			ft_initrule(t_rule *rule, char **tab);
t_philo			*ft_initphilo(t_rule *rule);
pthread_mutex_t	*ft_initfork(int no_of_philo);
int				ft_init(t_main *main, char **tab);

//pthread.c
void			sleep_think(t_philo *philo, t_main *main);
void			philo_eat(t_philo *philo, pthread_mutex_t *fork, t_main *main);
void			*routine(void *arg);
int				ft_strtheard(t_main *main);
void			threading(t_main *main);

//time.c
long			time_diff(long time);
long			get_ms(void);
void			time_to_action(long time_action);

#endif