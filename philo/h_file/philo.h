/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:22:02 by xray              #+#    #+#             */
/*   Updated: 2025/03/01 12:49:13 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

// includes
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

// structs

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;


// parsing 


int			check_m_p(char *s);

void		add(int *i, int *space, int *sign, char c);

int			check_strings(char *s);

int			is_sorted(t_list *s);

int			find_greater(t_list *s);

long long	ft_atoll(char *s, int *i, int *space);

int			ft_strlen_space(char *s);

t_list		*error(t_list *l);

t_list		*ft_lstmap(int *lst);

t_list		*parsing(int argc, char **t, t_list *l);

void		ft_lstadd_back(t_list **lst, t_list *n);

t_list		*ft_lstnew(int content);

void		ft_lstadd_front(t_list **lst, t_list *n);

void		ft_lstdelone(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstclear(t_list **lst);

int			ft_lstlen(t_list *l);

int			ft_recur(int n, char *ptr, int l);

int			is_negative(t_list *list);

#endif
