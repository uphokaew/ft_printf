/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:12 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 08:57:54 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	uintlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*convert_uint(unsigned int n)
{
	unsigned long	nbr;
	size_t			len;
	char			*s_uint;

	nbr = (unsigned long)n;
	len = uintlen(n);
	s_uint = (char *)ft_calloc(len + 1, sizeof(char));
	if (s_uint == NULL)
		return (NULL);
	if (nbr == 0)
		*(s_uint + 0) = '0';
	while (nbr > 0 && len > 0)
	{
		*(s_uint + (len - 1)) = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (s_uint);
}

int	ft_printuint(unsigned int n)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_uint(n);
	if (str == NULL)
		return (0);
	length = ft_printstr(str);
	free(str);
	return (length);
}
