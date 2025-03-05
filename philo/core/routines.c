/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:31:27 by xray              #+#    #+#             */
/*   Updated: 2025/03/05 11:49:26 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"
#include <pthread.h>
#include <unistd.h>

void	obs_routine(void	*glob)
{
	t_global	*global;
	int			i;
	int			eaten;

	global = (t_global *)glob;
	while (1)
	{
		i = -1;
		eaten = 0;
		while (++i)
		{
			if (global->philo[i].last_meal - get_current_time() >= global->time_before_death)
			{
				global->philo[i].alive = 0;
				print_message(global, "died", i);
				return ;
			}
			if (global->philo[i].need_to_eat <= 0)
				eaten++;
		}
		if (eaten == global->philo_number)
			return ;
	}
}

void	*philo_routine(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_action(philo, "has taken a fork");
		print_action(philo, "is eating");
		philo->need_to_eat--;
		philo->last_meal = get_current_time();
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		print_action(philo, "is sleeping");
		usleep(philo->time_to_sleep);
		print_action(philo, "is thinking");
	}
	return (NULL);
}


