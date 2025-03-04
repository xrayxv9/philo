/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:20 by xray              #+#    #+#             */
/*   Updated: 2025/03/04 13:30:26 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

void	core(int *time_list)
{
	t_global		global;
	pthread_mutex_t	forks;
	t_philo			philo;

	global.philo_number = time_list[0];
	global.time_before_death = time_list[1];
	global.time_to_eat = time_list[2];
	global.time_to_sleep = time_list[3];
	global.has_to_eat = time_list[4];
	pthread_mutex_init(&(global.print), NULL);
	init_global(&global, &forks, &philo);
	init_forks(&forks, &global);
	init_philo(&philo, &global);
	printf("philo : %p forks : %p\n", global.philo, global.forks);
	init_obs(&global);
	global.birth = get_current_time();
	lauch_them_all(&global);
	free_global(&global, NULL);
}
