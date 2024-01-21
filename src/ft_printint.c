/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:13:17 by uphokaew          #+#    #+#             */
/*   Updated: 2023/11/29 21:53:50 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	int		length;
	char	*str;

	length = 0;
	str = convert_int(n);
	if (str == NULL)
		return (0);
	length += ft_printstr(str);
	free(str);
	return (length);
}
