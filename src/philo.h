/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:28 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/30 10:00:09 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				eating;
	int				eat_count;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	int				id;
	int				life_status;
	int				last_meal_tick;
	int				time_death;
	pthread_mutex_t	lock;
	long long		start;
	struct s_input	*input;
}					t_philo;

typedef struct s_input
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	pthread_t			*monitor;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	struct s_philo		*philo;
}			t_input;

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"

# define TRUE 1
# define FALSE 0

//actions.c
void		psleep(t_philo *philo);
void		eat(t_philo *philo);
void		die(t_philo *philo);

//init.c
void		check(int argc, char **argv);
void		init_input(int argc, char **argv, t_input *input);
void		init_philos(t_input *input);
int			init_forks(t_input *input);
void		alloc(t_input *input);
void		routine(void *arg);
void		thread(t_input *input);
void		monitor(void *arg);

//utils.c
void		print_green(const char *message, int id,
				long long ms, t_input *input);
void		print_blue(const char *message, int id,
				long long ms, t_input *input);
void		print_red(const char *message, int id,
				long long ms, t_input *input);
int			ft_atoi(const char *str);
int			check_input(char **argv);
long long	timestamp(void);
void		ft_usleep(int time);

#endif
