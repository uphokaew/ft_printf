/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:25 by uphokaew          #+#    #+#             */
/*   Updated: 2023/12/17 21:32:30 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printstr(const char *s)
{
	int		length;
	size_t	i;

	length = 0;
	i = 0;
	if (s == NULL)
	{
		write(1, STRNULL, 6);
		return (6);
	}
	while (*(s + i) != '\0')
	{
		length += ft_printchr(*(s + i));
		i++;
	}
	return (length);
}
