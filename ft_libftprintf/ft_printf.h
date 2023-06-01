/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:25:07 by kbenjell          #+#    #+#             */
/*   Updated: 2023/02/23 00:09:44 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "conversion_functions/ft_printf_cf.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

#endif
