/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:31:09 by xray              #+#    #+#             */
/*   Updated: 2025/03/01 12:57:01 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"

int main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	if (argc == 5)
		printf("4 arguments\n");
	else if (argc == 6)
		printf("there are 5 args\n");
	else
		return (1);
	list = parsing(argc, argv, list);
	for (t_list *curr = list; curr; curr = curr->next)
	{
		printf("here is the number : %d\n", curr->content);
	}
}
