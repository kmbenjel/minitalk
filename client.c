/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:30:20 by kbenjell          #+#    #+#             */
/*   Updated: 2023/05/28 18:30:34 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c /= 2;
	}
}

void	ft_error(void)
{
	write(2, "\tERROR!\n", 8);
	exit(1);
}

int	ft_isspace(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_pid(const char *pid)
{
	int	i;

	i = 0;
	while (ft_isspace(pid[i]))
		i++;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			ft_error();
	}
	while (ft_isspace(pid[i]))
		i++;
	if (pid[i] != 0)
		ft_error();
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3 || av[1][0] == 0 || av[2][0] == 0)
		ft_error();
	ft_check_pid();
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		ft_send(pid, av[2][i]);
		i++;
	}
}
