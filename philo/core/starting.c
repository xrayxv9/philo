/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:24:44 by xray              #+#    #+#             */
/*   Updated: 2025/03/04 13:30:42 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	lauch_them_all(t_global	*global)
{
	int	nb;

	nb = -1;
	if (pthread_create(&(global->obs.th), NULL, (void *)obs_routine, global))
		free_global(global, "Observer couldn't be created");
	while (++nb < global->philo_number)
	{
		global->philo[nb].last_meal = get_current_time();
		pthread_mutex_lock(&global->print);
		printf("new_creation at : %lu\n", global->time_to_sleep);
		pthread_mutex_unlock(&global->print);
		if (pthread_create(&(global->philo[nb].th), NULL, (void *)philo_routine,
			&global->philo[nb]))
			free_global(global, "One of the philo has failed");
	}
	if (pthread_join(global->obs.th, NULL))
		free_global(global, "Join error on the observer");
	nb = -1;
	while (++nb < global->philo_number)
	{
		if (pthread_detach(global->philo[nb].th))
			free_global(global, "Couldn't detach a philo");
	}
}
