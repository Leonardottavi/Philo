/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:28 by lottavi           #+#    #+#             */
/*   Updated: 2023/11/29 12:59:25 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_imput
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}			t_imput;

typedef struct s_philo
{
	int	id;
	int	fork
}	t_philo;


# define NUM_ARGS "ERROR: The number of arguments must be 4 or 5"
# define ARG1 "ERROR: Non numerical parametres"

# define RESET "\e[0m"
# define RED "\033[0;31m"
# define GREEN "\e[0;32m"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

# define TRUE 1
# define FALSE 0

void	init_command(int argc, char **argv, t_imput *imput);
int		main(int argc, char **argv);

#endif
