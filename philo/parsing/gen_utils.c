/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:19:20 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/07 10:19:48 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

int	ft_strlen_space(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] == '0')
		j++;
	while ((s[j + i] && (s[j + i] >= '0' && s[j + i] <= '9'))
		|| s[i + j] == '-')
		i++;
	return (i);
}

long long	ft_atoll(char *s, int *i, int *space)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= '\t' && s[*i] <= '\r'))
		add(i, space, NULL, '0');
	if (s[*i] == '+' || s[*i] == '-')
		add(i, NULL, &sign, s[*i]);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		nbr = nbr * 10 + (s[*i] - '0');
		(*i)++;
	}
	nbr *= sign;
	return (nbr);
}

int	is_negative(t_list *list)
{
	t_list	*curr;

	curr = list;
	while (curr)
	{
		if (curr->content <= 0)
			return (0);
		curr = curr->next;
	}
	return (1);
}
