/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:00:13 by xray              #+#    #+#             */
/*   Updated: 2025/03/07 09:31:37 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"
#include <pthread.h>

void	*free_data(t_data *data, char *message)
{
	int	i;

	i = data->philo_number;
	while (--i >= 0)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->print));
	if (message)
		printf("Philo : %s\n", message);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	return (NULL);
}
