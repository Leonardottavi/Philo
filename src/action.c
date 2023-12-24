/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:01:03 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/06 10:01:03 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	psleep(t_input *input)
{
	pthread_mutex_lock(&input->philo->lock);
	print_blue("Philo is sleeping");
	ft_usleep(input->time_to_sleep);
	pthread_mutex_unlock(&input->philo->lock);
}

void choose_fork(t_input *input)
{
	if (pthread_mutex_trylock(&input->philo->fork_l) == 0)
	{
		if (pthread_mutex_trylock(&input->philo->fork_r) == 0)
			print_blue("Philo has taken both forks");
		else
			pthread_mutex_unlock(&input->philo->fork_l);
	}
	else
		print_red("Philo couldn't take the left fork");
}

void drop_fork(t_input *input)
{
	if (pthread_mutex_trylock(&input->philo->fork_r) == 0)
	{
		pthread_mutex_unlock(&input->philo->fork_r);
		print_blue("Philo dropped the right fork");
	}
	else if (pthread_mutex_trylock(&input->philo->fork_r) == EBUSY)
		print_red("Philo didn't have the right fork to drop");
	else
		print_red("Error while trying to drop the right fork");
if (pthread_mutex_trylock(&input->philo->fork_l) == 0)
	{
		pthread_mutex_unlock(&input->philo->fork_l);
		print_blue("Philo dropped the left fork");
	}
	else if (pthread_mutex_trylock(&input->philo->fork_l) == EBUSY)
		print_red("Philo didn't have the left fork to drop");
	else
		print_red("Error while trying to drop the left fork");
}

void	eat(t_input *input)
{
	choose_fork(input);
	pthread_mutex_lock(&input->philo->lock);
	print_green("Philo is eating");
	input->philo->eat_count++;
	ft_usleep(input->time_to_eat);
	pthread_mutex_unlock(&input->philo->lock);
	drop_fork(input);
}

void	die(t_input *input)
{
	int i = 0;
	while(input->time_to_die)
	{
		if(input->time_to_die == 0)
		{
			print_red("A philo is dead");
			exit(TRUE);
		}
		i--;
	}
}

void	routine(t_input *input)
{
	psleep(input);
	eat(input);
	die(input);
}
