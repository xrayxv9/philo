/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:31:09 by xray              #+#    #+#             */
/*   Updated: 2025/03/06 19:06:01 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"

int main(int argc, char **argv)
{
	t_list	*list;
	int		*time_list;

	list = NULL;
	if (argc != 5 && argc != 6)
		return (1);
	list = parsing(argc, argv, list);
	if (!list)
		return (1);
	time_list = malloc(5 * sizeof(int));
	time_list[0] = list->content;
	time_list[1] = list->next->content;
	time_list[2] = list->next->next->content;
	time_list[3] = list->next->next->next->content;
	if (list->next->next->next->next)
		time_list[4] = list->next->next->next->next->content;
	else
		time_list[4] = -1;
	ft_lstclear(&list);
	core(time_list);
	free(time_list);
}
