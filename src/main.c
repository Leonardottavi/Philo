/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/06 12:02:59 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_input *input)
{
	int	i;
	int	fail;

	i = 0;
	while (i < input->number_of_philosophers)
	{
		fail = pthread_create(input->t1 + i, NULL,
				&routine, (input->philo) + i);
		if (fail)
			return (0);
		i++;
	}
	return (1);
}

int	stop_threads(t_input *input)
{
	int	i;
	int	fail;

	i = 0;
	while (i < input->number_of_philosophers)
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
	t_input	*input;
	init_command(argc, argv, &input);
	create_threads(input);
	stop_threads(input);
	free(input);
}

