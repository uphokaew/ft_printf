/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:05:57 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 14:56:23 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long ptr)
{
	unsigned long long	temp;
	unsigned long long	div;
	int		length;
	char	*symbol;

	length = 2;
	symbol = "0123456789abcdef";
	div = 1;
	temp = ptr;
	while (temp >= 16)
	{
		temp /= 16;
		div *= 16;
	}
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
