/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:39:27 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/10 17:50:00 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_green(const char *message, int id, long long ms)
{
	printf("%s timestamp: %lld philo: %d %s %s\n", GREEN, ms, id, message, RESET);
}

void	print_blue(const char *message, int id, long long ms)
{
	printf("%s timestamp: %lld philo: %d %s %s\n", BLUE, ms, id, message, RESET);
}

void	print_red(const char *message, int id, long long ms)
{
	printf("%s timestamp: %lld philo: %d %s %s\n", RED, ms, id, message, RESET);
}

void	print_error(const char *message)
{
	printf("%s %s %s\n", RED, message, RESET);
}
