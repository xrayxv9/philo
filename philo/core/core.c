/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:20 by xray              #+#    #+#             */
/*   Updated: 2025/03/06 17:38:37 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <string.h>

void	core(int *time_list)
{
	t_data			data;
	pthread_mutex_t	forks[time_list[0]];
	t_philo			philo[time_list[0]];
	t_obs			obs;

	data.obs = &obs;
	data.philo_number = time_list[0];
	data.time_before_death = time_list[1];
	data.time_to_eat = time_list[2];
	data.time_to_sleep = time_list[3];
	data.has_to_eat = time_list[4];
	data.time_begin = get_current_time(0);
	data.philo = philo;
	data.forks = forks;
	pthread_mutex_init(&(data.print), NULL);
	init_data(&data);
	data.forks = init_forks(forks, &data);
	data.philo = init_philo(philo, &data);
	data.birth = get_current_time(0);
	lauch_them_all(&data);
	free_data(&data, NULL);
}
