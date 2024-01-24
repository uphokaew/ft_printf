/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:06:46 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/24 16:56:05 by uphokaew         ###   ########.fr       */
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

static void	specifier(const char specifier, va_list args, t_printf *p_len)
{
	if (specifier == 'c')
		p_len->length += ft_printchr(va_arg(args, int));
	else if (specifier == 's')
		p_len->length += ft_printstr(va_arg(args, const char *));
	else if (specifier == 'd' || specifier == 'i')
		p_len->length += ft_printint(va_arg(args, int));
	else if (specifier == 'u')
		p_len->length += ft_printuint(va_arg(args, unsigned int));
	else if (specifier == 'x')
		p_len->length += ft_printhex(va_arg(args, unsigned int), 'a');
	else if (specifier == 'X')
		p_len->length += ft_printhex(va_arg(args, unsigned int), 'A');
	else if (specifier == 'p')
		p_len->length += ft_printptr(va_arg(args, void *));
	else if (specifier == '%')
		p_len->length += ft_printchr('%');
}

int	ft_printf(const char *s, ...)
{
	t_printf	print;

	print.length = 0;
	va_start (print.args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (checkspecifier("cspdiuxX%", *s) != 0)
				specifier(*s, print.args, &print);
			else
			{
				print.length += ft_printchr('%');
				print.length += ft_printchr(*s);
			}
		}
		else
			print.length += ft_printchr(*s);
		s++;
	}
	va_end(print.args);
	return (print.length);
}
