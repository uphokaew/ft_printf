/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:10:38 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 08:54:25 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexlen(unsigned int hex)
{
	size_t	len;

	len = 0;
	if (hex <= 0)
		len = 1;
	while (hex > 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static char	*convert_hex(unsigned int n, int c)
{
	size_t	len;
	int		i;
	char	*s_hex;

	len = hexlen(n);
	s_hex = (char *)ft_calloc(len + 1, sizeof(char));
	if (s_hex == NULL)
		return (NULL);
	while (len > 0)
	{
		i = n % 16;
		if (i < 10)
			*(s_hex + (len - 1)) = '0' + (n % 16);
		else
			*(s_hex + (len - 1)) = (char)c + (n % 16) - 10;
		n /= 16;
		len--;
	}
	return (s_hex);
}

int	ft_printhex(unsigned int hex, int c)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_hex(hex, c);
	if (str == NULL)
		return (0);
	length = ft_printstr(str);
	free(str);
	return (length);
}
