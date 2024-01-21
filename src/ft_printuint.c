/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:12 by uphokaew          #+#    #+#             */
/*   Updated: 2023/11/29 18:32:34 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int n)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_uint(n);
	if (str == NULL)
		return (0);
	length += ft_printstr(str);
	free(str);
	return (length);
}
