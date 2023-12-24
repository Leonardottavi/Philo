/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:28 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/24 15:31:32 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>

typedef struct s_philo
{
	int				eating;
	int				eat_count;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	id;
	pthread_mutex_t	lock;
}	t_philo;

typedef struct s_input
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	struct	s_philo	*philo;
}			t_input;

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"

# define TRUE 1
# define FALSE 0

void	psleep(t_input *input);
void choose_fork(t_input *input);
void drop_fork(t_input *input);
void	eat(t_input *input);
void	die(t_input *input);
//
long long	timestamp(void);
void	ft_usleep(int ms);;
int	ft_calc_num_str(const char *str);
int	ft_atoi(const char *str);
//
void	init_philos(t_input *input);
void	init_input(int argc, char **argv, t_input *input);
//
void print_green(const char *message);
void print_blue(const char *message);
void print_red(const char *message);

#endif
