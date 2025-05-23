/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:31:27 by xray              #+#    #+#             */
/*   Updated: 2025/03/13 10:42:46 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"
#include <pthread.h>
#include <unistd.h>

void	*all_eaten(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->alive_mutex);
	while (++i < data->philo_number)
		data->philo[i].alive = 0;
	pthread_mutex_unlock(&data->alive_mutex);
	pthread_mutex_lock(&data->print);
	printf("All philosophers have eaten enough\n");
	pthread_mutex_unlock(&data->print);
	return (NULL);
}

void	*obs_routine(t_data *data)
{
	int		i;
	int		count;

	while (1)
	{
		i = -1;
		count = 0;
		while (++i < data->philo_number)
		{
			pthread_mutex_lock(&data->last_meal_mutex);
			pthread_mutex_lock(&data->alive_mutex);
			if ((get_current_time(0) - data->philo[i].last_meal
					>= data->time_before_death) || !data->philo[i].alive)
				return (kill_all(data, i));
			pthread_mutex_unlock(&data->last_meal_mutex);
			pthread_mutex_unlock(&data->alive_mutex);
			pthread_mutex_lock(&data->need_to_eat_mutex);
			if (data->philo[i].need_to_eat == 0)
				count++;
			pthread_mutex_unlock(&data->need_to_eat_mutex);
		}
		if (count == data->philo_number)
			return (all_eaten(data));
		usleep(500);
	}
}

void	eat(t_philo *philo)
{
	int	id;

	id = philo->id % 2;
	if (id)
	{
		pthread_mutex_lock(philo->l_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_action(philo, "has taken a fork");
	}
	print_action(philo, "is eating");
	pthread_mutex_lock(philo->last_meal_mutex);
	philo->last_meal = get_current_time(0);
	pthread_mutex_unlock(philo->last_meal_mutex);
	ft_usleep(philo, philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	change_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->need_to_eat_mutex);
	if (philo->need_to_eat != 0 && philo->need_to_eat != -1)
		philo->need_to_eat--;
	pthread_mutex_unlock(philo->need_to_eat_mutex);
}

void	*philo_routine(void	*ph)
{
	t_philo	*philo;
	int		alive;

	philo = (t_philo *)ph;
	pthread_mutex_lock(philo->alive_mutex);
	alive = philo->alive;
	pthread_mutex_unlock(philo->alive_mutex);
	while (alive)
	{
		eat(philo);
		change_eat(philo);
		print_action(philo, "is sleeping");
		ft_usleep(philo, philo->time_to_sleep);
		print_action(philo, "is thinking");
		pthread_mutex_lock(philo->alive_mutex);
		alive = philo->alive;
		pthread_mutex_unlock(philo->alive_mutex);
		usleep(800);
	}
	return (NULL);
}
