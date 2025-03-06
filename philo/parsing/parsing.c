/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:13:14 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/06 19:06:35 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

int	ft_is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')
				|| (s[i] >= '0' && s[i] <= '9') || s[i] == '+'
				|| s[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	add(int *i, int *space, int *sign, char c)
{
	(*i)++;
	if (space)
		(*space)++;
	if (sign)
	{
		if (c == '-')
			(*sign) = -1;
	}
}

int	addlist(char *s, t_list **l, int i, int space)
{
	long long		nbr;
	int				len;

	len = ft_strlen_space(s + i);
	if (s[i] == '-' || s[i] == '+')
		len++;
	if (len > 10)
		return (0);
	nbr = ft_atoll(s, &i, &space);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (0);
	if (space - 1 > 0)
		ft_lstadd_back(l, ft_lstnew((int)nbr));
	else
		return (0);
	if (s[i] != '\0' && check_strings(s + i))
		return (addlist(s, l, i, 1));
	return (1);
}

t_list	*parsing(int argc, char **t, t_list *l)
{
	int		i;

	i = 1;
	l = NULL;
	while (i < argc)
	{
		if (!ft_is_digit(t[i]) || !check_strings(t[i]) || !check_m_p(t[i]))
			return (error(l));
		if (!addlist(t[i], &l, 0, 2))
			return (error(l));
		i++;
	}
	if (!is_negative(l))
		return (error(l));
	return (l);
}
