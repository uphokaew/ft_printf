/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:06:46 by uphokaew          #+#    #+#             */
/*   Updated: 2023/12/17 21:07:27 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkspecifier(const char *specifier, int c)
{
	size_t	index;

	index = 0;
	while (*(specifier + index) != '\0')
	{
		if (*(specifier + index) == (char)c)
			return (1);
		index++;
	}
	return (0);
}

static int	format_specifier(const char specifier, va_list args)
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
		length += ft_printptr(va_arg(args, uintptr_t));
	return (length);
}

int	ft_printf(const char *s, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start (args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			while (*(s + 1) == ' ')
				s++;
			s++;
			if (*s == '%')
				length += ft_printchr(*s);
			else if (checkspecifier("cspdiuxX", *s) != 0)
				length += format_specifier(*s, args);
		}
		else
			length += ft_printchr(*s);
		s++;
	}
	va_end(args);
	return (length);
}
