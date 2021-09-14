/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:48:41 by mdaillet          #+#    #+#             */
/*   Updated: 2021/09/13 13:52:36 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				nb_philo;
	int				ntpe;
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				*over;
	long			t_start;
	int				meal_count;
	long			meal_prec;
	pthread_mutex_t	*prev_fork;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*meals;
	pthread_mutex_t	fork;
}				t_data;

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_error(void);
long	ft_get_time(void);
void	ft_usleep(int len);
void	ft_print(long time, int id, char *status);
void	ft_destroy_mutexes(t_data *data);
int		ft_check_arg(int ac, char **av);
void	ft_philo(t_data *data);

#endif
