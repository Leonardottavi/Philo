/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/10 17:21:51 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		print_error("ERROR: The number of arguments must be 4 or 5\n");
		exit(EXIT_SUCCESS);
	}
	if (check_input (argv) == 1)
	{
		print_error("ERROR: Non numerical parametres\n");
		exit(EXIT_SUCCESS);
	}
}

void	thread(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->number_of_philosophers)
	{
		pthread_create(&input->philo[i].thread, NULL,
			(void *)routine, &input->philo[i]);
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < input->number_of_philosophers)
	{
		pthread_join(input->philo[i].thread, NULL);
		i++;
	}
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
