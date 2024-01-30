/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/30 21:34:55 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->input->life_status == TRUE)
	{
		if (philo->id % 2 == 0)
			ft_usleep(100);
		eat(philo);
		if (philo->input->life_status == FALSE)
			break ;
		psleep(philo);
	}
}

void	monitor(void *arg)
{
	t_input	*input;
	int		i;

	input = (t_input *)arg;
	while (input->life_status == TRUE)
	{
		i = 0;
		while (i < input->num_philo)
		{
			ft_usleep(input->time_to_die);
			if (input->num_philo == 1)
				die(input->philo);
			if (input->philo->eat_count >= input->num_must_eat && input->num_must_eat == TRUE)
			{
				pthread_mutex_lock(&input->print);
				printf("All philosophers have eaten\n");
				input->life_status = FALSE;
				break;
			}
			if (input->philo->last_meal_tick >= input->philo->time_death && input->philo->eating == FALSE)
			{
				die(input->philo);
				break;
			}
			i++;
		}
	}
}

void	thread(t_input *input)
{
	int	i;

	i = 0;
	pthread_create(input->monitor, NULL, (void *)monitor, input);
	while (i < input->num_philo)
	{
		pthread_create(&input->philo[i].thread, NULL, (void *)routine, &input->philo[i]);
		i++;
	}
	while (i < input->num_philo)
	{
		pthread_join(input->philo[i].thread, NULL);
		i++;
	}
	pthread_join(*input->monitor, NULL);
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
	ft_exit(&input);
	return (0);
}
