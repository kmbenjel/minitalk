/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:30:40 by kbenjell          #+#    #+#             */
/*   Updated: 2023/06/02 10:24:11 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	static pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", (int)pid);
	while (1)
	{
		pause();
	}
	return (0);
}
