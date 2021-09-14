/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:14:01 by mdaillet          #+#    #+#             */
/*   Updated: 2021/09/11 12:39:39 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(long time, int id, char *status)
{
	long	tmp;

	tmp = ft_get_time() - time;
	if (id == 0)
		printf("%ld\033[32m\tEveryone has eaten enough !\n\033[0m", tmp);
	else if (!ft_strcmp(status, "EAT"))
		printf("%ld\033[32m\tPhilo number %d is eating\n\033[0m", tmp, id);
	else if (!ft_strcmp(status, "SLEEP"))
		printf("%ld\033[34m\tPhilo number %d is sleeping\n\033[0m", tmp, id);
	else if (!ft_strcmp(status, "THINK"))
		printf("%ld\033[36m\tPhilo number %d is thinking\n\033[0m", tmp, id);
	else if (!ft_strcmp(status, "DIE"))
		printf("%ld\033[31m\tPhilo number %d is dead\n\033[0m", tmp, id);
	else if (!ft_strcmp(status, "FORK"))
		printf("%ld\033[37m\tPhilo number %d has taken a fork\n\033[0m", tmp, id);
}
