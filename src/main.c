/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:44 by lottavi           #+#    #+#             */
/*   Updated: 2024/01/04 15:58:13 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	t_input	input;
	check(argc, argv);
	init_input(argc, argv, &input);
	init_philos(&input);
	thread_create(&input);
	//free(input);
}

