/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:20 by xray              #+#    #+#             */
/*   Updated: 2025/03/05 11:48:22 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

void	core(int *time_list)
{
	t_global		global;
	pthread_mutex_t	forks[time_list[0]];
	t_philo			philo[time_list[0]];

	global.philo_number = time_list[0];
	global.time_before_death = time_list[1];
	global.time_to_eat = time_list[2];
	global.time_to_sleep = time_list[3];
	global.has_to_eat = time_list[4];
	global.philo = philo;
	global.forks = forks;
	pthread_mutex_init(&(global.print), NULL);
	init_global(&global, forks, philo);
	global.forks = init_forks(forks, &global);
	global.philo = init_philo(philo, &global);
	init_obs(&global);
	global.birth = get_current_time();
	lauch_them_all(&global);
	free_global(&global, NULL);
}
