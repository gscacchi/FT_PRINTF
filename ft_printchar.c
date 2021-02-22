/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:21:21 by gscala            #+#    #+#             */
/*   Updated: 2021/02/16 19:21:23 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printchar(va_list ap, t_flags flags)
{
	int i;
	int b;
	char c;

	i = 0; 
	b = va_arg(ap, int);
	c = (char)b;

	if (flags.width > 1)
	{
		if (flags.minus == 1) 
			i += ft_putchar(c);
		while (flags.width-- > 1)
			i += ft_putchar(' ');
		if (flags.minus == 0)
			i += ft_putchar(c);
	}
	else
		i += ft_putchar(c);
	return (i);
}
