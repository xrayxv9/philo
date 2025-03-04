/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:00:13 by xray              #+#    #+#             */
/*   Updated: 2025/03/04 12:02:22 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	*free_global(t_global *global, char *message)
{
	while (--(global->philo_number) >= 0)
		pthread_mutex_destroy(&(global->forks[global->philo_number]));
	pthread_mutex_destroy(&(global->print));
	if (global->philo)
		free(global->philo);
	if (global->obs.alive)
		free(global->obs.alive);
	if (message)
		printf("Philo : %s\n", message);
	return (NULL);
}
