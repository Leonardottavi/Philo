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
	if(mutex_status(&input->philo->fork_l) == 0)
	{
		pthread_mutex_lock(&input->philo->fork_l);
		print_green("Philo has taken the left fork");
	}
	if(mutex_status(&input->philo->fork_r) == 0)
	{
		pthread_mutex_lock(&input->philo->fork_r);
		print_green("Philo has taken the right fork");
	}
}

void drop_fork(t_input *input)
{
	if(mutex_status(&input->philo->fork_l) == 1)
	{
		pthread_mutex_unlock(&input->philo->fork_l);
		print_green("Philo has drop the left fork");
	}
	if(mutex_status(&input->philo->fork_r) == 1)
	{
		pthread_mutex_unlock(&input->philo->fork_r);
		print_green("Philo has drop the right fork");
	}
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
