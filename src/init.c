/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/29 18:12:44 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("ERROR: The number of arguments must be 4 or 5\n");
		exit(EXIT_SUCCESS);
	}
	if (check_input (argv) == 1)
	{
		printf("ERROR: Non numerical parametres\n");
		exit(EXIT_SUCCESS);
	}
}

void	alloc(t_input *input)
{
	input->philo = (t_philo *)malloc(sizeof(t_philo) * input->num_philo);
	if (!input->philo)
	{
		printf("ERROR: Philo allocation failed\n");
		exit(EXIT_SUCCESS);
	}
	input->forks = malloc(sizeof(pthread_mutex_t) * input->num_philo);
	if (!input->forks)
	{
		printf("ERROR: Forks allocation failed\n");
		exit(EXIT_SUCCESS);
	}
}

void	init_input(int argc, char **argv, t_input *input)
{
	input->num_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&input->print, NULL);
	if (argc == 6)
		input->num_must_eat = ft_atoi(argv[5]);
	else
		input->num_must_eat = FALSE;
}

void	init_philos(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philo)
	{
		input->philo[i].eating = 0;
		input->philo[i].eat_count = 0;
		input->philo[i].id = i + 1;
		input->philo[i].life_status = 1;
		input->philo[i].last_meal_tick = 0;
		pthread_mutex_init(&input->philo[i].lock, NULL);
		input->philo[i].input = input;
		input->philo[i].start = timestamp();
		input->philo[i].time_death = input->time_to_die;
		i++;
	}
}

int	init_forks(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->num_philo)
		pthread_mutex_init(&input->forks[i], NULL);
	i = 0;
	input->philo[0].fork_l = &input->forks[0];
	input->philo[0].fork_r = &input->forks[input->num_philo - 1];
	i = 1;
	while (i < input->num_philo)
	{
		input->philo[i].fork_l = &input->forks[i];
		input->philo[i].fork_r = &input->forks[i - 1];
		i++;
	}
	return (0);
}
