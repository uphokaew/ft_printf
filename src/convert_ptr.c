/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:08:53 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/20 13:27:51 by uphokaew         ###   ########.fr       */
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

char	*convert_ptr(uintptr_t ptr)
{
	char	*s_ptr;
	size_t	len;
	size_t	i;

	len = ptrlen(ptr);
	s_ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (s_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(s_ptr + (len - 1 - i)) = HEX[ptr % 16];
		ptr /= 16;
		i++;
	}
	return (s_ptr);
}
