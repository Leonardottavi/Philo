/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/29 10:10:54 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->start = timestamp();
	while (philo->life_status == TRUE)
	{
		if (philo->id % 2 == 0)
			ft_usleep(100);
		eat(philo);
		psleep(philo);
	}
}

void	monitor(void *arg)
{
	t_input	*input;
	int		i;

	input = (t_input *)arg;
	ft_usleep(input->time_to_die);
	while (TRUE)
	{
		i = 0;
		while (i < input->number_of_philosophers)
		{
			if (input->number_of_philosophers == 1)
				die(input->philo);
			if (input->philo->last_meal >= input->philo->time_death)
				die(input->philo);
			if (input->number_of_times_each_philosopher_must_eat >= input->philo->eat_count)
			{
				printf("All philosophers have eaten\n");
				exit(EXIT_SUCCESS);
			}
			i++;
		}
	}
}

void	thread(t_input *input)
{
	int	i;

	i = 0;
	pthread_create(&input->monitor, NULL, (void *)monitor, input);
	while (i < input->number_of_philosophers)
	{
		pthread_create(&input->philo[i].thread, NULL, (void *)routine, &input->philo[i]);
		i++;
	}
	while (i < input->number_of_philosophers)
	{
		pthread_join(input->philo[i].thread, NULL);
		i++;
	}
	pthread_join(input->monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_input	input;

	check(argc, argv);
	init_input(argc, argv, &input);
	alloc(&input);
	init_philos(&input);
	init_forks(&input);
	thread(&input);
	return (0);
}
