/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:41:46 by kbenjell          #+#    #+#             */
/*   Updated: 2023/02/23 01:49:16 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_cf.h"

static char	*ft_uitoa(unsigned int uiarg)
{
	char	*str;
	char	*free_helper;
	int		remainder;
	int		i;

	remainder = 0;
	i = 0;
	str = malloc(11);
	free_helper = str;
	if (!uiarg)
		str[i++] = '0';
	while (uiarg)
	{
		remainder = uiarg % 10;
		str[i++] = remainder + '0';
		uiarg /= 10;
	}
	str[i] = '\0';
	str = ft_reverse_string(str);
	free(free_helper);
	return (str);
}

// Max unsigned int length is 10 digits.

int	ft_print_unsigned(va_list ap)
{
	int				count;
	unsigned int	uiarg;
	char			*uistr;

	count = 0;
	uiarg = va_arg(ap, unsigned int);
	uistr = ft_uitoa(uiarg);
	ft_putstr_fd(uistr, 1);
	count = ft_strlen(uistr);
	free(uistr);
	return (count);
}

//  UITOA stands for: Unsigned Integer to ASCII.
//  UIARG stands for: Unsigned Integer Argument.
//  UISTR stands for: Unsigned Integer String.
