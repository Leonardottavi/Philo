/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/08 12:24:37 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_input *input)
{
	int	i;

	i = 0;
	while (i <= input->number_of_philosophers)
	{
		input->philo[i].eating = 0;
		input->philo[i].eat_count = 0;
		pthread_mutex_init(&input->philo[i].fork1, NULL);
		pthread_mutex_init(&input->philo[i].fork2, NULL);
		pthread_mutex_init(&input->philo[i].id, NULL);
		i++;
	}
}

void	init_input(int argc, char **argv, t_input *input)
{
	int i = 0;
	pthread_mutex_init(&input[i].lock, NULL);
	if (argc < 5 || argc > 6)
		print_red("ERROR: The number of arguments must be 4 or 5");
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
		if (ft_atoi(argv[i]) == TRUE)
			{
			print_red("ERROR: Non numerical parametres");
			exit(TRUE);
			}
			i++;
		}
		input->number_of_philosophers = ft_atoi(argv[1]);
		input->time_to_die = ft_atoi(argv[2]);
		input->time_to_eat = ft_atoi(argv[3]);
		input->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			input->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			input->number_of_times_each_philosopher_must_eat = FALSE;
	}
}

void	*routine(t_input *input)
{
	int	i;

	i = 0;
	while (i <= input->number_of_philosophers)
	{

		psleep(input);
		think(input);
		choose_fork(input);
		eat(input);
		drop_fork(input);
	}
	return (NULL);
}
