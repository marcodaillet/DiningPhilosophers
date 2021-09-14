/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:45:44 by mdaillet          #+#    #+#             */
/*   Updated: 2021/09/13 13:53:40 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nb_philo)
		pthread_mutex_destroy(&data[i++].fork);
}

void	*ft_death_thread(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	while (1)
	{
		if (ft_get_time() - data->meal_prec > data->t_die)
		{
			ft_print(data->t_start, data->id, "DIE");
			pthread_mutex_unlock(data->dead);
			return (NULL);
		}
		else if (data->ntpe != -1 && data->meal_count >= data->ntpe)
		{
			ft_usleep((float)data->id);
			pthread_mutex_unlock(data->meals);
			return (NULL);
		}
	}
	return (NULL);
}

void	*ft_meal_count_thread(void *param)
{
	t_data	*data;
	int		mc;

	mc = 0;
	data = (t_data *)param;
	if (data->ntpe != 0)
		pthread_mutex_lock(data->meals);
	while (data->ntpe != 0 && mc < data->nb_philo)
	{
		pthread_mutex_lock(data->meals);
		mc++;
	}
	ft_print(data->t_start, 0, "OVER");
	pthread_mutex_unlock(data->dead);
	return (NULL);
}	

void	*ft_philo_thread(void *param)
{
	pthread_t	th;
	t_data		*data;

	data = (t_data *)param;
	pthread_create(&th, NULL, ft_death_thread, data);
	if (!(data->id % 2))
		ft_usleep((float)data->t_eat * 0.9 + 1);
	while (data->ntpe == -1 || data->ntpe > data->meal_count)
	{
		pthread_mutex_lock(&data->fork);
		ft_print(data->t_start, data->id, "FORK");
		pthread_mutex_lock(data->prev_fork);
		ft_print(data->t_start, data->id, "FORK");
		data->meal_prec = ft_get_time();
		ft_print(data->t_start, data->id, "EAT");
		ft_usleep(data->t_eat);
		pthread_mutex_unlock(&data->fork);
		pthread_mutex_unlock(data->prev_fork);
		data->meal_count++;
		ft_print(data->t_start, data->id, "SLEEP");
		ft_usleep(data->t_sleep);
		ft_print(data->t_start, data->id, "THINK");
	}
	return (NULL);
}

void	ft_philo(t_data *data)
{
	int				i;
	pthread_mutex_t	dead;
	pthread_mutex_t	meals;
	pthread_t		th;

	data[0].prev_fork = &data[data[0].nb_philo - 1].fork;
	pthread_mutex_init(&dead, NULL);
	pthread_mutex_init(&meals, NULL);
	pthread_mutex_lock(&dead);
	i = 0;
	while (i < data[0].nb_philo)
	{
		data[i].dead = &dead;
		data[i].meals = &meals;
		pthread_create(&th, NULL, ft_philo_thread, &data[i++]);
	}
	if (data[0].ntpe != -1)
		pthread_create(&th, NULL, ft_meal_count_thread, &data[0]);
	pthread_mutex_lock(&dead);
	ft_destroy_mutexes(data);
	pthread_mutex_destroy(&dead);
	pthread_mutex_destroy(&meals);
	free(data);
}
