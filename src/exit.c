/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:10 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/31 15:36:50 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freestack(t_input *input)
{
	if (input->monitor)
	{
		free(input->monitor);
		input->monitor = NULL;
	}
	if (input->philo)
	{
		free(input->philo);
		input->philo = NULL;
	}
	if (input->forks)
	{
		free(input->forks);
		input->forks = NULL;
	}
}

void	ft_exit(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philo)
	{
		if (!pthread_mutex_destroy(&input->print))
			break ;
		if (!pthread_mutex_destroy(&input->philo[i].lock))
			break ;
		if (!pthread_mutex_destroy(&input->forks[i]))
			break ;
		i++;
	}
	freestack(input);
}
