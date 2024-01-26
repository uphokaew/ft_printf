/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:05:57 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 15:07:06 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(uintptr_t ptr, int length, uintptr_t div)
{
	char	*symbol;

	symbol = "0123456789abcdef";
	if (write(1, "0x", 2) == -1)
		return (-1);
	while (div > 0)
	{
		if (write(1, (symbol + (ptr / div)), 1) == -1)
			return (0);
		length++;
		ptr %= div;
		div /= 16;
	}
	return (length);
}

int	ft_printptr(uintptr_t ptr)
{
	uintptr_t	temp;
	uintptr_t	div;
	int			length;

	length = 2;
	div = 1;
	if (ptr == 0)
		return (ft_printstr(PNULL));
	temp = ptr;
	while (temp >= 16)
	{
		temp /= 16;
		div *= 16;
	}
	return (print_ptr(ptr, length, div));
}
