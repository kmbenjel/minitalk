/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_uppercase.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:41:22 by kbenjell          #+#    #+#             */
/*   Updated: 2023/02/22 23:21:58 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_cf.h"

static void	ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	ft_print_hexadecimal_uppercase(va_list ap)
{
	int		uiarg;
	int		count;
	char	*hex;

	uiarg = va_arg(ap, int);
	hex = ft_uitoh(uiarg);
	ft_strupcase(hex);
	ft_putstr_fd(hex, 1);
	count = ft_strlen(hex);
	free(hex);
	return (count);
}

//  FT_UITOH stands for: Unsigned Integer To Hexadecimal.
//  UIARG stands for: Unsigned Integer Argument.
