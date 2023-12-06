/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:09 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/06 11:09:00 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_calc_num_str(const char *str)
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

void	init_command(int argc, char **argv, t_input *input)
{
	int i = 0;
	if (argc < 5 || argc > 6)
		print_red("ERROR: The number of arguments must be 4 or 5")
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
		if (ft_atoi(argv[i]) == FALSE)
			{
			print_red("ERROR: Non numerical parametres")
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
