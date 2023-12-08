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
	pthread_mutex_lock(&input->lock);
	print_blue("Philo is sleeping");
	usleep(input->time_to_sleep);
	pthread_mutex_unlock(&input->lock);
}

void	think(t_input *input)
{
	pthread_mutex_lock(&input->philo->id);
	printf("Philo is thinking");
	pthread_mutex_unlock(&input->philo->id);
}

void	choose_fork(t_input *input)
{
	pthread_mutex_lock(&input->philo->fork1);
	print_blue("Philo has taken the left fork");
	pthread_mutex_lock(&input->philo->fork2);
	print_blue("Philo has taken the right fork");
}

void	drop_fork(t_input *input)
{
	pthread_mutex_lock(&input->philo->fork1);
	pthread_mutex_unlock(&input->philo->fork2);
	usleep(input->time_to_eat);
}

void	eat(t_input *input)
{
	choose_fork(input);
	pthread_mutex_lock(&input->lock);
	input->philo->eating = 1;
	print_green("Philo is eating");
	input->philo->eat_count++;
	usleep(input->time_to_eat);
	pthread_mutex_unlock(&input->lock);
	drop_fork(input);
}
