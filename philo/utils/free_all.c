/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:00:13 by xray              #+#    #+#             */
/*   Updated: 2025/03/06 17:13:17 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	*free_data(t_data *data, char *message)
{
	while (--(data->philo_number) >= 0)
		pthread_mutex_destroy(&(data->forks[data->philo_number]));
	pthread_mutex_destroy(&(data->print));
	if (message)
		printf("Philo : %s\n", message);
	return (NULL);
}
