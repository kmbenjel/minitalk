/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:48:45 by kbenjell          #+#    #+#             */
/*   Updated: 2023/02/23 01:19:02 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_isspec(char c)
{
	if (c && ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

static int	ft_convert(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_print_character(ap));
	else if (spec == 's')
		return (ft_print_string(ap));
	else if (spec == 'p')
		return (ft_print_pointer(ap));
	else if (spec == 'd' || spec == 'i')
		return (ft_print_decimal(ap));
	else if (spec == 'u')
		return (ft_print_unsigned(ap));
	else if (spec == 'x')
		return (ft_print_hexadecimal_lowercase(ap));
	else if (spec == 'X')
		return (ft_print_hexadecimal_uppercase(ap));
	else
		return (ft_print_percent());
}

int	ft_printf(const char *format, ...)
{
	int		ol;
	char	*i;
	va_list	ap;

	i = (char *)format;
	va_start(ap, format);
	ol = 0;
	while (*i)
	{
		if (*i == '%')
		{
			if (ft_isspec(*(i + 1)))
				ol += ft_convert(*(i + 1), ap);
			i++;
		}
		else
		{
			ft_putchar_fd(*i, 1);
			ol++;
		}
		i++;
	}
	va_end(ap);
	return (ol);
}

// i iterates on every character in the format.
// ap stands for: Argument Pointer.
// ol stands for: Output Length.
