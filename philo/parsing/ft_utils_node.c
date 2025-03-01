/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:56:15 by cmorel            #+#    #+#             */
/*   Updated: 2025/03/01 12:27:40 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../h_file/philo.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	elem->index = 0;
	return (elem);
}

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	if (!lst || !(*lst))
	{
		n->next = NULL;
		*lst = n;
	}
	else
	{
		n->next = *lst;
		*lst = n;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;

	while (*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = curr;
	}
	free(*lst);
	(*lst) = NULL;
}
