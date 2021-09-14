/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:50:04 by mdaillet          #+#    #+#             */
/*   Updated: 2021/09/13 13:53:11 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_init(t_data *data, char **av, int tmp)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&data[i].fork, NULL);
		if (i != 0)
			data[i].prev_fork = &data[i - 1].fork;
		else
			data[i].prev_fork = NULL;
		data[i].nb_philo = ft_atoi(av[1]);
		data[i].t_die = ft_atoi(av[2]);
		data[i].t_eat = ft_atoi(av[3]);
		data[i].t_sleep = ft_atoi(av[4]);
		data[i].t_start = ft_get_time();
		data[i].ntpe = tmp;
		data[i].meal_prec = data[i].t_start;
		data[i].meal_count = 0;
		data[i].id = i + 1;
		data[i].over = 0;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (!(ft_check_arg(ac, av)) || !(ft_atoi(av[1])))
		return (ft_error());
	data = malloc(sizeof(t_data) * ft_atoi(av[1]));
	if (!data)
		return (1);
	if (ac == 6)
		ft_init(data, av, ft_atoi(av[5]));
	else
		ft_init(data, av, -1);
	ft_philo(data);
	return (0);
}
