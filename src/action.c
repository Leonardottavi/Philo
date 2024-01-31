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
}

void	eat(t_philo *philo)
{
	takefork(philo);
	pthread_mutex_lock(&philo->lock);
	print_green("is eating", philo->id, (timestamp() - philo->start), philo->input);
	philo->last_meal_tick = timestamp() - philo->start;
	philo->time_death = philo->input->time_to_die + philo->last_meal_tick;
	ft_usleep(philo->input->time_to_eat);
	philo->eating = TRUE;
	philo->eat_count++;
	printf("last meal: %lld id %d\n", philo->last_meal_tick, philo->id);
	printf("time death: %lld id %d\n", philo->time_death, philo->id);
	philo->eating = FALSE;
	pthread_mutex_unlock(&philo->lock);
	dropfork(philo);
}

void	die(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	print_red("philo is dead", philo->id, (timestamp() - philo->start), philo->input);
	philo->input->life_status = FALSE;
	pthread_mutex_unlock(&philo->lock);
}

void	psleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	print_blue("is sleeping", philo->id, (timestamp() - philo->start), philo->input);
	ft_usleep(philo->input->time_to_sleep);
	pthread_mutex_unlock(&philo->lock);
	print_blue("is thinking", philo->id, (timestamp() - philo->start), philo->input);
}
