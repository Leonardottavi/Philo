/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/10 17:42:47 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alloc(t_input *input)
{
	input->philo = (t_philo *)malloc(sizeof(t_philo) * input->number_of_philosophers);
	input->forks = malloc(sizeof(pthread_mutex_t) * input->number_of_philosophers);
	if (!input->forks)
	{
		print_error("ERROR: Forks allocation failed\n");
		exit(EXIT_SUCCESS);
	}
	if (!input->philo)
	{
		print_error("ERROR: Philo allocation failed\n");
		exit(EXIT_SUCCESS);
	}
	if (!input)
	{
		print_error("ERROR: Input allocation failed\n");
		exit(EXIT_SUCCESS);
	}
}

void	init_input(int argc, char **argv, t_input *input)
{
	input->number_of_philosophers = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		input->number_of_times_each_philosopher_must_eat = FALSE;
}

void	init_philos(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->number_of_philosophers)
	{
		input->philo[i].eating = 0;
		input->philo[i].eat_count = 0;
		input->philo[i].id = i + 1;
		input->philo[i].life_status = 1;
		input->philo[i].last_meal = timestamp();
		pthread_mutex_init(&input->philo[i].lock, NULL);
		input->philo[i].input = input;
		input->philo[i].start = timestamp();
		i++;
	}
}

int	init_forks(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->number_of_philosophers)
		pthread_mutex_init(&input->forks[i], NULL);
	i = 0;
	input->philo[0].fork_l = &input->forks[0];
	input->philo[0].fork_r = &input->forks[input->number_of_philosophers - 1];
	i = 1;
	while (i < input->number_of_philosophers)
	{
		input->philo[i].fork_l = &input->forks[i];
		input->philo[i].fork_r = &input->forks[i - 1];
		i++;
	}
	return (0);
}

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->life_status == 1)
	{
		philo->start = timestamp();
		if (philo->id % 2 == 0)
			ft_usleep(100);
		if (philo->input->number_of_philosophers == 1)
			die(philo);
		eat(philo);
		psleep(philo);
		if (philo->input->time_to_die >= timestamp() - philo->last_meal)
			die(philo);
		if (philo->input->number_of_times_each_philosopher_must_eat == philo->input->philo->eat_count)
		{
			exit(EXIT_SUCCESS);
		}
	}
}
