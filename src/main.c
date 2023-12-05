/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/04 16:10:15 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_threads(t_input *input)
{
	int	i;
	int	fail;

	i = 0;
	while (i < input->philo_count)
	{
		fail = pthread_create(input->t1 + i, NULL,
				&routine, (input->philo) + i);
		if (fail)
			return (0);
		i++;
	}
	return (1);
}

static int	stop_threads(t_input *input)
{
	int	i;
	int	fail;

	i = 0;
	while (i < input->philo_count)
	{
		fail = pthread_detach(input->t1[i]);
		if (fail)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_imput	imput;
	init_command(argc, argv, &input);
	free(input);
	free(philo);
	free(philo->forks);
}

