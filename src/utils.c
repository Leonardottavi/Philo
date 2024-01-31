/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:23:05 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/31 14:25:17 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;
	int	i;

	neg = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num += (str[i] - 48);
		i++;
	}
	num *= neg;
	return (num);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_exit(t_input *input)
{
	int	i;

	i = 0;
	if (input->philo)
		free(input->philo);
	if (input->forks)
		free(input->forks);
	if (input->monitor)
		free(input->monitor);
	while (i < input->num_philo)
	{
		pthread_mutex_destroy(&input->print);
		pthread_mutex_destroy(&input->philo->lock);
		pthread_mutex_destroy(input->forks);
		i++;
	}
	return (0);
}
