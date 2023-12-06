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

u_int64_t
	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	eat(t_philo *philo, t_input *input)
{
	philo->last_meal = get_time();
	usleep(input->time_to_eat);
}

void	choose_forks(t_input *input)
{
	if(input->philo)
}

void	pick_up_forks(t_input *input)
{
	choose_forks(input, fork1, fork2);
	pthread_mutex_lock(input->philo->forks + fork1);
	pthread_mutex_lock(&input->philo->t1);
	print_blue("Philo has taken the left fork");
	pthread_mutex_unlock(&input->philo->t1);
	pthread_mutex_lock(input->philo->forks + fork2);
	pthread_mutex_lock(&input->philo->t1);
	print_blue("Philo has taken the right fork");
	pthread_mutex_unlock(&input->philo->t1);
}

void	let_go_forks(t_philo *philo, t_input *input)
{
	pthread_mutex_unlock(philo->forks + ((philo->sit + 1)
			% input->number_of_philosophers));
	pthread_mutex_unlock(philo->forks + philo->sit);
}

void	*routine(t_input *input, t_philo *philo)
{
	while (1)
	{
		pick_up_forks(input);
		pthread_mutex_lock(&philo->t1);
		print_green("Philo is eating");
		pthread_mutex_unlock(&philo->t1);
		eat(philo, input);
		pthread_mutex_lock(&philo->t1);
		print_blue("Philo is sleeping");
		pthread_mutex_unlock(&philo->t1);
		let_go_forks(philo, input);
		usleep(input->time_to_sleep - 10);
		pthread_mutex_lock(&philo->t1);
		printf("Philo is thinking");
		pthread_mutex_unlock(&philo->t1);
	}
	return (NULL);
}
