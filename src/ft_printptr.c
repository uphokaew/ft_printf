/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:05:57 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/25 23:24:18 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ptrlen(uintptr_t ptr)
{
	size_t	len;

	len = 0;
	if (ptr <= 0)
		len = 1;
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static char	*convert_ptr(void *p)
{
	char		*s_ptr;
	size_t		len;
	size_t		i;
	uintptr_t	ptr;

	ptr = (uintptr_t)p;
	len = ptrlen(ptr);
	s_ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (s_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(s_ptr + (len - 1 - i)) = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i++;
	}
	return (s_ptr);
}

int	ft_printptr(void *ptr)
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
