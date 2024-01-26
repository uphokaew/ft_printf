/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:12 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 13:52:04 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int n)
{
	int				length;
	int				ret;
	unsigned int	temp;
	unsigned int	div;

	div = 1;
	length = 0;
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
