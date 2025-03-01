/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_node_remains.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:01:14 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/01 12:27:39 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = n;
	else
		*lst = n;
}

t_list	*ft_lstmap(int *lst)
{
	t_list	*result;
	t_list	*new_content;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	result = NULL;
	while (lst[i])
	{
		new_content = ft_lstnew(lst[i]);
		if (!new_content)
		{
			ft_lstclear(&result);
			free(new_content);
			return (NULL);
		}
		ft_lstadd_back(&result, new_content);
		i++;
	}
	return (result);
}

int	ft_lstlen(t_list *l)
{
	int		i;
	t_list	*curr;

	if (!l)
		return (0);
	curr = l;
	i = 0;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
