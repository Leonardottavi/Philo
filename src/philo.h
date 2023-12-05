/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:28 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/04 16:12:46 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	pthread_t		t1;
	int				id;
	int				status;
	int				eating;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_input
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_philo	*philo
}			t_input;

# define NUM_ARGS "ERROR: The number of arguments must be 4 or 5"
# define ARG1 "ERROR: Non numerical parametres"
# define TDERR "CREATING THREAD ERROR"

# define RESET "\e[0m"
# define RED "\033[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\033[0;34m"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

# define TRUE 1
# define FALSE 0

void	init_command(int argc, char **argv, t_input *input);
int		main(int argc, char **argv);
void	p_take_fork(t_philo *philo);
void	p_sleep(t_philo *philo);
void	p_dead(t_philo *philo);
void	p_eat(t_philo *philo);

#endif
