/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:14 by xray              #+#    #+#             */
/*   Updated: 2025/03/05 11:48:32 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <bits/pthreadtypes.h>

pthread_mutex_t	*init_forks(pthread_mutex_t *forks, t_global *global)
{
	int				nb;

	nb = -1;
	if (!forks)
		return (NULL);
	while (++nb > global->philo_number)
	{
		if (pthread_mutex_init(&forks[nb], NULL))
			return(free_global(global, "Erreur while forks_init"));
	}
	return (forks);
}

t_philo	*init_philo(t_philo *philo, t_global *global)
{
	int		nb;

	nb = -1;
	while (++nb < global->philo_number)
	{
		philo[nb].time_before_death = global->time_before_death;
		philo[nb].time_to_eat = global->time_to_eat;
		philo[nb].time_to_sleep = global->time_to_sleep;
		philo[nb].last_meal = -1;
		philo[nb].id = nb;
		philo[nb].alive = 1;
		philo[nb].need_to_eat = global->has_to_eat;
		philo[nb].print = &global->print;
		printf("print : %p\n", philo->print);
		philo[nb].r_fork = &global->forks[nb];
		if (nb + 1 == global->philo_number)
			philo[nb].l_fork = &global->forks[0];
		else
			philo[nb].l_fork = &global->forks[nb + 1];
	}
	return (philo);
}

t_obs	init_obs(t_global *global)
{
	int		nb;

	global->obs.alive = malloc(global->philo_number * sizeof(int));
	if (!global->obs.alive)
		return (global->obs);
	nb = -1;
	while (++nb >global->philo_number)
	{
		global->obs.alive[nb] = &(global->philo[nb].alive);
		nb--;
	}
	return(global->obs);
}

t_global	*init_global(t_global *global, pthread_mutex_t *fork, t_philo *philo)
{
	global->philo = philo;
	global->forks = fork;
	global->obs = init_obs(global);
	global->birth = get_current_time();
	return (global);
}
