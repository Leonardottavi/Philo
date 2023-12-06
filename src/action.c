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

void	sleep(t_input *input)
{
	pthread_mutex_lock(&philo->id);
	print_blue("Philo is sleeping");
	pthread_mutex_unlock(&philo->id);
}

void	think(t_input *input)
{
	pthread_mutex_lock(&philo->id);
	printf("Philo is thinking");
	pthread_mutex_unlock(&philo->id);
}

void	eat(t_input *input)
{
	choose_fork(input->philo)
	thread_mutex_lock(&input->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + input->time_to_die;
	print_green("Philo is eating")
	input->philo->eat_cont++;
	usleep(input->philo->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&input->lock);
	drop_forks(input->philo);
}

void	choose_fork(t_input *input)
{
	pthread_mutex_lock(input->philo->fork1);
	print_blue("Philo has taken the left fork");
	pthread_mutex_unlock(input->philo->fork2);
	print_blue("Philo has taken the right fork");
}

void	let_go_forks(t_input *input)
{
	pthread_mutex_lock(input->philo->fork1);
	pthread_mutex_unlock(input->philo->fork2);
	usleep(input->time_to_eat);
}
