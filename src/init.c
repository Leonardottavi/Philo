/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/05 20:52:21 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		print_red("ERROR: The number of arguments must be 4 or 5\n");
		exit(EXIT_SUCCESS);
	}
	if(check_input(argv) == 1)
	{
		print_red("ERROR: Non numerical parametres\n");
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

void	alloc(t_input *input)
{
	input->philo = malloc(sizeof(t_philo) * input->number_of_philosophers);
	if (!input->philo)
	{
		print_red("ERROR: Malloc failed\n");
		exit(EXIT_SUCCESS);
	}
}

void	init_philos(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->number_of_philosophers)
	{
		input->philo[i].eating = 0;
		input->philo[i].eat_count = 0;
		pthread_mutex_init(&input->philo[i].fork_l, NULL);
		pthread_mutex_init(&input->philo[i].fork_r, NULL);
		pthread_mutex_init(&input->philo[i].id, NULL);
		pthread_mutex_init(&input->philo[i].lock, NULL);
		i++;
	}
}

void	routine(void *arg)
{
	eat(arg);
	psleep(arg);
}

void	thread(t_input *input)
{
	int i;

	i = 0;
	while (i < input->number_of_philosophers)
	{
		pthread_create(&input->philo[i].thread, NULL, (void *)routine, &input->philo[i]);
		i++;
	}
	i = 0;
	while (i < input->number_of_philosophers)
	{
		pthread_join(input->philo[i].thread, NULL);
		i++;
	}
}
