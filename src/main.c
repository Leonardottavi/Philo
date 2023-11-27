/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2023/11/27 16:07:36 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_calc_num_str(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == 0)
			num = (str[i] - '0');
		else
			num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	if (min == 1)
		return (ft_calc_num_str(str + i) * (-1));
	return (ft_calc_num_str(str + i));
}

int	main(int argc, char *argv)
{
	int	i = 0;
	t_imput	imput;

	if (argc < 5 || argc > 6)
		printf(RED, NUM_ARGS, RESET);

		printf(RED, ARG1, RESET);
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			if (ft_atoi(argv[i]) == FALSE)
				{
				printf(RED, ARG1, RESET);
				exit(TRUE);
				}
			i++;
		}
		imput.number_of_philosophers = ft_atoi(argv[1]);
		imput.time_to_die = ft_atoi(argv[2]);
		imput.time_to_eat = ft_atoi(argv[3]);
		imput.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			imput.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			imput.number_of_times_each_philosopher_must_eat = FALSE;
	}
	return (TRUE);
}

void	init()
{

}
