/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:03:27 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/30 17:04:04 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_input	*input)
{
	if (input->monitor)
		free(input->monitor);
	if (input->forks)
		free(input->forks);
	if (input->philo)
		free(input->philo);
}

void	ft_exit(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->num_philo)
	{
		pthread_mutex_destroy(&input->forks[i]);
		pthread_mutex_destroy(&input->philo[i].lock);
	}
	pthread_mutex_destroy(&input->print);
	pthread_mutex_destroy(&input->philo->lock);
	clear_data(input);
}

int	error(char *str, t_input *input)
{
	printf("%s\n", str);
	if (input)
		ft_exit(input);
	return (1);
}
