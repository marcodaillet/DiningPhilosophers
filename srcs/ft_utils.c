/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:46:05 by mdaillet          #+#    #+#             */
/*   Updated: 2021/08/31 17:32:12 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep(int len)
{
	long	time;

	time = ft_get_time();
	while (ft_get_time() < time + len)
		usleep(len);
}

long	ft_get_time(void)
{
	static struct timeval	tv;
	long					time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + (tv.tv_usec / 1000); // Convert to milliseconds
	return (time);
}

int	ft_error(void)
{
	printf("\033[0;31mERROR : \033[0m");
	printf("\033[0;31mwrong arguments : ");
	printf("\033[0;31musage --> ./philo \033[0m");
	printf("\033[0;31m[nb of philo] [time to die] \033[0m");
	printf("\033[0;31m[time to eat]\033[0m");
	printf("\033[0;31m [time to sleep]\033[0m");
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (s1[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}
