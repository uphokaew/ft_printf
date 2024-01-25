/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:06:46 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 00:09:31 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(int c)
{
	return (write(1, &c, 1));
}

static int	specifier_check(const char specifier, va_list args)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length += ft_printchr(va_arg(args, int));
	else if (specifier == 's')
		length += ft_printstr(va_arg(args, const char *));
	else if (specifier == 'd' || specifier == 'i')
		length += ft_printint(va_arg(args, int));
	else if (specifier == 'u')
		length += ft_printuint(va_arg(args, unsigned int));
	else if (specifier == 'x')
		length += ft_printhex(va_arg(args, unsigned int), 'a');
	else if (specifier == 'X')
		length += ft_printhex(va_arg(args, unsigned int), 'A');
	else if (specifier == 'p')
		length += ft_printptr(va_arg(args, void *));
	else if (specifier == '%')
		length += ft_printchr('%');
	else
	{
		length += ft_printchr('%');
		length += ft_printchr(specifier);
	}
	return (length);
}

int	ft_printf(const char *s, ...)
{
	t_printf	print;

	print.length = 0;
	print.temp = 0;
	va_start (print.args, s);
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == '%')
			print.temp = specifier_check(*(++s), print.args);
		else
			print.temp = ft_printchr(*s);
		if (print.temp == -1)
			return (-1);
		print.length += print.temp;
		s++;
	}
	va_end(print.args);
	return (print.length);
}
