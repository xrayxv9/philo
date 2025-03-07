/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:24:44 by xray              #+#    #+#             */
/*   Updated: 2025/03/07 09:51:13 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	lauch_them_all(t_data	*data)
{
	int	nb;

	nb = -1;
	while (++nb < data->philo_number)
	{
		data->philo[nb].last_meal = get_current_time(0);
		if (pthread_create(&(data->philo[nb].th), NULL, (void *)philo_routine,
				&data->philo[nb]))
			free_data(data, "One of the philo has failed");
	}
	obs_routine(data);
	nb = -1;
	while (++nb < data->philo_number)
	{
		if (pthread_join(data->philo[nb].th, NULL))
			free_data(data, "Couldn't detach a philo");
	}
}
