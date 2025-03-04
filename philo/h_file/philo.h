/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:22:02 by xray              #+#    #+#             */
/*   Updated: 2025/03/04 13:18:36 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

// includes

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

// structs

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct	s_philo
{
	int				id;
	int				last_meal;
	int				need_to_eat;
	int				alive;
	size_t			time_before_death;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_t		th;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}					t_philo;

typedef	struct	s_obs
{
	int			**alive;
	pthread_t	th;
}		t_obs;
typedef	struct	s_global
{
	size_t			time_before_death;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				has_to_eat;
	int				philo_number;
	int				birth;
	t_obs			obs;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_global;

// parsing 


int			check_m_p(char *s);

void		add(int *i, int *space, int *sign, char c);

int			check_strings(char *s);

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

void		*free_global(t_global *global, char *message);

size_t		get_current_time();

void		print_message(t_global *global, char *message, int nb);

void		obs_routine(void	*glob);

void		lauch_them_all(t_global	*global);

void		*philo_routine(void	*glob);

void		print_action(t_philo *philo, char *message);

void		core(int *time_list);

t_obs		init_obs(t_global *global);

t_philo	*init_philo(t_philo *philo, t_global *global);

pthread_mutex_t	*init_forks(pthread_mutex_t *forks, t_global *global);

t_global	*init_global(t_global *global, pthread_mutex_t *fork, t_philo *philo);
#endif
