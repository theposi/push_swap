/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:52:12 by crizapat          #+#    #+#             */
/*   Updated: 2024/09/12 14:27:17 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * Prints data based on a specific format.
 * @param format The initial point of the list.
 * @param ... The rest of the variable arguments.
 */
int	ft_printf(char const *format, ...)
{
	int			i;
	int			printed_chars;
	va_list		args;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			format_catcher(format[i], args, &printed_chars);
		}
		else
		{
			ft_putchar(format[i], &printed_chars);
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
