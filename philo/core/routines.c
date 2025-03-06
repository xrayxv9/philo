/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:31:27 by xray              #+#    #+#             */
/*   Updated: 2025/03/06 18:59:29 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"
#include <pthread.h>
#include <unistd.h>

void	all_eaten(t_data *data)
{
	pthread_mutex_lock(&data->print);
	printf("All philosophers have eaten enough\n");
	pthread_mutex_unlock(&data->print);
}

void	obs_routine(t_data *data)
{
	int		i;
	int		count;

	while (1)
	{
		i = -1;
		count = 0;
		while (++i < data->philo_number)
		{
			if (get_current_time(0) - data->philo[i].last_meal >= data->time_before_death || !data->philo[i].alive)
			{
				print_message(data, "died (boo le nul)", i);
				return ;
			}
			if (data->philo[i].need_to_eat == 0)
				count++;
		}
		if (count == data->philo_number)
		{
			all_eaten(data);
			return ;
		}
		usleep(500);
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else if (!(philo->id % 2))
		pthread_mutex_lock(philo->r_fork);
	print_action(philo, "has taken a fork");
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);
	else if (!(philo->id % 2))
		pthread_mutex_lock(philo->l_fork);
	print_action(philo, "has taken a fork");
}

void	*philo_routine(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (philo->alive)
	{
		take_fork(philo);
		print_action(philo, "is eating");
		if (philo->need_to_eat != 0 && philo->need_to_eat != -1)
			philo->need_to_eat--;
		philo->last_meal = get_current_time(0);
		ft_usleep(philo, philo->time_to_eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		print_action(philo, "is sleeping");
		ft_usleep(philo, philo->time_to_sleep);
		print_action(philo, "is thinking");
	}
	return (NULL);
}
