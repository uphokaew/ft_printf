/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:05:57 by uphokaew          #+#    #+#             */
/*   Updated: 2023/11/29 22:54:18 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(uintptr_t ptr)
{
	int		length;
	char	*str;

	length = 0;
	str = NULL;
	if (ptr == 0)
		length += ft_printstr(PNULL);
	else
	{
		length += ft_printstr("0x");
		str = convert_ptr(ptr);
		if (str == NULL)
			return (0);
		length += ft_printstr(str);
	}
	free(str);
	return (length);
}