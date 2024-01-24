/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:25 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/23 20:01:09 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(const char *s)
{
	int		length;
	size_t	i;

	length = 0;
	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*(s + i) != '\0')
	{
		length += ft_printchr(*(s + i));
		i++;
	}
	return (length);
}
