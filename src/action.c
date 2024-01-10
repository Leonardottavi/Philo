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

void	psleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	print_blue("is sleeping", philo->id, (timestamp() - philo->start));
	ft_usleep(philo->input->time_to_sleep);
	pthread_mutex_unlock(&philo->lock);
	print_blue("is thinking", philo->id, (timestamp() - philo->start));
}

void	choose_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_green("has taken a fork", philo->id, (timestamp() - philo->start));
	pthread_mutex_lock(philo->fork_r);
	print_green("has taken a fork", philo->id, (timestamp() - philo->start));
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	eat(t_philo *philo)
{
	choose_fork(philo);
	pthread_mutex_lock(&philo->lock);
	print_green("is eating", philo->id, (timestamp() - philo->start));
	philo->eat_count++;
	ft_usleep(philo->input->time_to_eat);
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}

void	die(t_philo *philo)
{
	philo->life_status = 0;
	print_red("philo is dead", philo->id, (timestamp() - philo->start));
	exit(EXIT_SUCCESS);
}
