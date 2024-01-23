/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:27:27 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/23 17:01:15 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# ifdef __linux__
#  define PNULL "(nil)"
# elif __APPLE__
#  define PNULL "0x0"
# endif

# define HEX "0123456789abcdef"
# define STRNULL "(null)"

typedef struct t_printf
{
	int	length;
}					t_printf;

int		ft_printchr(int c);
int		ft_printstr(const char *s);
int		ft_printint(int n);
int		ft_printuint(unsigned int n);
int		ft_printhex(unsigned int hex, int c);
int		ft_printptr(uintptr_t ptr);
int		ft_printf(const char *s, ...);

char	*convert_int(int n);
char	*convert_uint(unsigned int n);
char	*convert_hex(unsigned int n, int c);
char	*convert_ptr(uintptr_t ptr);
#endif
