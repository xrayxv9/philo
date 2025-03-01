/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:54:21 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/01 12:27:41 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

int	ft_recur(int n, char *ptr, int l)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (ptr)
		ptr[l--] = '\0';
	while (n >= 10)
	{
		if (ptr)
			ptr[l--] = (char)((n % 10) + '0');
		n /= 10;
		len++;
	}
	if (ptr)
		ptr[l] = (char)((n % 10) + '0');
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*t;
	int				sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_recur(n, NULL, 0) + sign;
	t = malloc((len + 2) * sizeof(char));
	if (!t)
		return (NULL);
	if (sign)
		t[0] = '-';
	if (!t)
		return (NULL);
	ft_recur(n, t, len + 1);
	return (t);
}
