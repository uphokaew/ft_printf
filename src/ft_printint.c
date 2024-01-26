/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:13:17 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 13:39:45 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digit(int n, int length)
{
	int	temp;
	int	div;
	int	ret;

	div = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		div *= 10;
	}
	while (div > 0)
	{
		ret = n / div + '0';
		if (write(1, &ret, 1) == -1)
			return (-1);
		length++;
		n %= div;
		div /= 10;
	}
	return (length);
}

int	ft_printint(int n)
{
	int		length;

	length = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		length++;
	}
	return (print_digit(n, length));
}
