/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:55:18 by gscala            #+#    #+#             */
/*   Updated: 2021/02/25 15:55:27 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa(size_t n)
{
	int		len;
	char	*c;

	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	return (c);
}


int 	ft_printu(va_list ap, t_flags flags)
{
	int 			i;
	unsigned int 	n;
	int 			len;
	char 			*c;

	i = 0;
	n = va_arg(ap, unsigned int);
	c = ft_utoa(n);
	if (flags.prec == 0 && c[0] == '0')
		c[0] = 0;
	if ((flags.minus == 1 && flags.zero == 1))
		flags.zero = 0;
	len = ft_strlen(c);
	if (flags.prec > flags.width && flags.prec > len)
	{
		i += ft_print_zero(flags.prec - len);
		i += ft_puts(c);
	}
	else if (flags.width > len && flags.prec >= len)
		i += ft_int_widthandprec(flags, c, len);
	else if (flags.width > len)
		i += ft_int_width(flags, c, len);
	else if (flags.prec > 0 && flags.width == 0)
	{
		if (flags.prec > len)
			i+=ft_print_zero(flags.prec - len);
		i+=ft_puts(c);
	}
	else 
	{
		i+=ft_puts(c);
	}
	return(i);
}
