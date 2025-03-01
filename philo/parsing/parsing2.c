/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:05:12 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/01 12:27:48 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

t_list	*error(t_list *l)
{
	printf("Error\n");
	if (l)
		ft_lstclear(&l);
	return (NULL);
}

int	check_strings(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_m_p(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
		{
			i++;
			if (!(s[i] >= '0' && s[i] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}
