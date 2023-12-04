/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:39:27 by lottavi           #+#    #+#             */
/*   Updated: 2023/12/04 15:39:03 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philo *philo)
{
	printf("%s%s%s\n," GREEN, EAT, RESET);
}

void	p_dead(t_philo *philo)
{
	printf("%s%s%s\n," RED, DIED, RESET);
}

void	p_sleep(t_philo *philo)
{
	printf("%s%s%s\n," SLEEP);
}

void	p_take_fork(t_philo *philo)
{
	printf("%s%s%s\n," BLUE, FORK, RESET);
}
