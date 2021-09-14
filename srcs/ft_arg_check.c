/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:47:26 by mdaillet          #+#    #+#             */
/*   Updated: 2021/08/31 16:08:56 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (0);
	i = 1;
	while (av[i])
	{
		if (!isnum(av[i]))
			return (0);
		i++;
	}
	return (1);
}
