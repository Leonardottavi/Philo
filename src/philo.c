/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:39:06 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/04 16:13:24 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(s_input *input)
{
	int i = 0
	while (i < input->number_of_philosophers)
	{
		if (pthread_create(input->philo->t1, NULL, &routine, NULL) != 0)
		{
			printf("ERRORE CREAZIONE THREAD\n");
			exit(1);
		}
	}
}

int	init_forks(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->number_of_philosophers)
		pthread_mutex_init(&input->forks[i], NULL);
	i = 0;
	input->philo[0].l_fork = &input->forks[0];
	input->philo[0].r_fork = &input->forks[input->number_of_philosophers - 1];
	i = 1;
	while (i < input->number_of_philosophers)
	{
		input->philos[i].l_fork = &input->forks[i];
		input->philos[i].r_fork = &input->forks[i - 1];
		i++;
	}
	return (0);
}
