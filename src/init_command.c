/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2023/11/29 12:08:48 by lottavi          ###   ########.fr       */
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

void	init_command(int argc, char **argv, t_imput *imput)
{
	int i = 0;
	if (argc < 5 || argc > 6)
		printf("%s%s%s\n", RED, NUM_ARGS, RESET);
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
		if (ft_atoi(argv[i]) == FALSE)
			{
			printf("%s%s%s\n", RED, ARG1, RESET);
			exit(TRUE);
			}
			i++;
		}
		imput->number_of_philosophers = ft_atoi(argv[1]);
		imput->time_to_die = ft_atoi(argv[2]);
		imput->time_to_eat = ft_atoi(argv[3]);
		imput->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			imput->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			imput->number_of_times_each_philosopher_must_eat = FALSE;
	}
}
