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

void	takefork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_green("has taken a fork", philo->id,
		(timestamp() - philo->start), philo->input);
	pthread_mutex_lock(philo->fork_r);
	print_green("has taken a fork", philo->id,
		(timestamp() - philo->start), philo->input);
}

void	dropfork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	print_blue("is sleeping", philo->id,
		(timestamp() - philo->start), philo->input);
	ft_usleep(philo->input->time_to_sleep);
}

void	eat(t_philo *philo)
{

	takefork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = TRUE;
	philo->time_death = timestamp() - philo->start + philo->input->time_to_die;
	print_green("is eating", philo->id, (timestamp() - philo->start), philo->input);
	philo->eat_count++;
	ft_usleep(philo->input->time_to_eat);
	philo->eating = FALSE;
	pthread_mutex_unlock(&philo->lock);
	dropfork(philo);
}

void	die(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	print_red("philo is dead", philo->id,
		(timestamp() - philo->start), philo->input);
	philo->life_status = FALSE;
	pthread_mutex_unlock(&philo->lock);
	exit(EXIT_SUCCESS);
}
