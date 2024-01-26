/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:06:58 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 10:54:52 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_digit(int n, int base)
{
	size_t	len;
	long	nbr;

	len = 0;
	nbr = (long)n;
	if (nbr == 0)
		len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (count > SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = count * size;
	while (i > 0)
	{
		*(char *)(p + (i - 1)) = '\0';
		i--;
	}
	return (p);
}
