/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:39:27 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/30 21:35:44 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_green(const char *message, int id, long long ms, t_input *input)
{
	pthread_mutex_lock(&input->print);
	printf("%s %lld %d %s %s\n", GREEN, ms, id, message, RESET);
	pthread_mutex_unlock(&input->print);
}

void	print_blue(const char *message, int id, long long ms, t_input *input)
{
	pthread_mutex_lock(&input->print);
	printf("%s %lld %d %s %s\n", BLUE, ms, id, message, RESET);
	pthread_mutex_unlock(&input->print);
}

void	print_red(const char *message, int id, long long ms, t_input *input)
{
	pthread_mutex_lock(&input->print);
	printf("%s %lld %d %s %s\n", RED, ms, id, message, RESET);
	pthread_mutex_unlock(&input->print);
}
