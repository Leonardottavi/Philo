/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:28 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/06 12:47:00 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				eating;
	int				last_meal;
	int				sit;
	int				fork1;
	int				fork2;
	pthread_mutex_t	*forks;
	pthread_mutex_t	t1;
}	t_philo;

typedef struct s_input
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_philo	*philo;
}			t_input;

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"

# define TRUE 1
# define FALSE 0

//main
int			create_threads(t_input *input);
int			stop_threads(t_input *input);
int			main(int argc, char **argv);

//init_command
void		init_command(int argc, char **argv, t_input *input);

//print_color
void		print_green(const char *message);
void		print_blue(const char *message);
void		print_red(const char *message);

//routine
void		*routine(t_input *input, t_philo *philo);

#endif
