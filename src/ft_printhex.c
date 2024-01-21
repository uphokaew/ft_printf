/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:10:38 by uphokaew          #+#    #+#             */
/*   Updated: 2023/11/29 21:53:59 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int hex, int c)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_hex(hex, c);
	if (str == NULL)
		return (0);
	length += ft_printstr(str);
	free(str);
	return (length);
}
