/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:17 by xray              #+#    #+#             */
/*   Updated: 2025/03/13 10:30:11 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

size_t	get_current_time(size_t t)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - t);
}

void	*print_message(t_data *data, char *message, int nb)
{
	pthread_mutex_lock(&data->print);
	printf("%lu philosopher %d %s\n", get_current_time(data->time_begin),
		nb, message);
	pthread_mutex_unlock(&(data->print));
	return (NULL);
}

void	print_action(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->alive_mutex);
	if (philo->alive)
	{
		pthread_mutex_lock(philo->print);
		printf("%lu philosopher %d %s\n", get_current_time(philo->time_begin),
			philo->id, message);
		pthread_mutex_unlock(philo->print);
	}
	pthread_mutex_unlock(philo->alive_mutex);
}

void	ft_usleep(t_philo *philo, size_t time)
{
	size_t	start;

	start = get_current_time(0);
	while (get_current_time(0) - philo->last_meal < philo->time_before_death
		&& get_current_time(0) - start <= time)
		usleep(500);
}

void	*kill_all(t_data *data, int nb)
{
	int	i;

	i = -1;
	pthread_mutex_unlock(&data->alive_mutex);
	pthread_mutex_unlock(&data->last_meal_mutex);
	print_message(data, "died (boo le nul)", nb);
	while (++i < data->philo_number)
	{
		pthread_mutex_lock(&data->alive_mutex);
		data->philo[i].alive = 0;
		pthread_mutex_unlock(&data->alive_mutex);
	}
	return (NULL);
}
