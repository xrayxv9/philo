/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:17 by xray              #+#    #+#             */
/*   Updated: 2025/03/04 12:02:36 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

size_t get_current_time()
{
	struct timeval time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_global *global, char *message, int nb)
{
	pthread_mutex_lock(&(global->print));
	printf("%lu philosopher number %d %s\n", get_current_time(), nb, message);
	pthread_mutex_unlock(&(global->print));
}

void	print_action(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->print);
	printf("%lu philosopher number %d %s\n",get_current_time(), philo->id, message);
	pthread_mutex_unlock(philo->print);
}
