/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:24:44 by xray              #+#    #+#             */
/*   Updated: 2025/03/07 11:42:46 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	alone(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(philo->r_fork);
	print_action(philo, "has taken a fork");
	ft_usleep(philo, philo->time_before_death);
	pthread_mutex_unlock(philo->r_fork);
}

void	lauch_them_all(t_data	*data)
{
	int	nb;

	nb = -1;
	while (++nb < data->philo_number && data->philo_number > 1)
	{
		data->philo[nb].last_meal = get_current_time(0);
		if (pthread_create(&(data->philo[nb].th), NULL, (void *)philo_routine,
				&data->philo[nb]))
			free_data(data, "One of the philo has failed");
	}
	if (data->philo_number == 1)
	{
		data->philo[0].last_meal = get_current_time(0);
		if (pthread_create(&data->philo[0].th, NULL, (void *)alone,
				&data->philo[0]))
			free_data(data, "The philo has failed");
	}
	obs_routine(data);
	nb = -1;
	while (++nb < data->philo_number)
	{
		if (pthread_join(data->philo[nb].th, NULL))
			free_data(data, "Couldn't detach a philo");
	}
}
