/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:14 by xray              #+#    #+#             */
/*   Updated: 2025/03/07 09:19:13 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <bits/pthreadtypes.h>

pthread_mutex_t	*init_forks(pthread_mutex_t *forks, t_data *data)
{
	int				nb;

	forks = malloc(data->philo_number * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	nb = -1;
	if (!forks)
		return (NULL);
	while (++nb < data->philo_number)
	{
		if (pthread_mutex_init(&forks[nb], NULL))
			return (free_data(data, "Erreur while forks_init"));
	}
	return (forks);
}

t_philo	*init_philo(t_philo *philo, t_data *data)
{
	int		nb;

	philo = malloc(data->philo_number * sizeof(t_philo));
	if (!philo)
		return (NULL);
	nb = -1;
	while (++nb < data->philo_number)
	{
		philo[nb].time_before_death = data->time_before_death;
		philo[nb].time_to_eat = data->time_to_eat;
		philo[nb].time_to_sleep = data->time_to_sleep;
		philo[nb].last_meal = -1;
		philo[nb].id = nb;
		philo[nb].alive = 1;
		philo[nb].need_to_eat = data->has_to_eat;
		philo[nb].time_begin = data->time_begin;
		philo[nb].print = &data->print;
		philo[nb].r_fork = &data->forks[nb];
		if (nb + 1 == data->philo_number)
			philo[nb].l_fork = &data->forks[0];
		else
			philo[nb].l_fork = &data->forks[nb + 1];
	}
	return (philo);
}
