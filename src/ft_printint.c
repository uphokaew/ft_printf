/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:13:17 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 10:54:41 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_int(int n)
{
	size_t	len;
	char	*s_int;
	long	nbr;

	nbr = (long)n;
	len = len_digit(n, 10);
	s_int = (char *)ft_calloc(len + 1, sizeof(char));
	if (s_int == NULL)
		return (NULL);
	if (nbr == 0)
		*(s_int + 0) = '0';
	if (nbr < 0)
	{
		*(s_int + 0) = '-';
		nbr *= -1;
	}
	while (nbr > 0 && len > 0)
	{
		*(s_int + (len - 1)) = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (s_int);
}

int	ft_printint(int n)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_int(n);
	if (str == NULL)
		return (0);
	length = ft_printstr(str);
	free(str);
	return (length);
}
