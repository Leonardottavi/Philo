/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:39:27 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/06 10:19:31 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_green(const char *message)
{
	printf("%s%s%s\n", GREEN, message, RESET);
}

void print_blue(const char *message)
{
	printf("%s%s%s\n", BLUE, message, RESET);
}

void print_red(const char *message)
{
	printf("%s%s%s\n", BLUE, message, RESET);
}
