/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:33:26 by gscala            #+#    #+#             */
/*   Updated: 2021/02/13 15:33:28 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_prec(char *s, t_flags flags, int l)
{
	int k;
	int i;

	k = 0;
	i = 0;
	if (flags.prec < l)
	{
		while (flags.prec-- > 0)
			i += ft_putchar(s[k++]);
	}
	else if (flags.prec >= l)
	{
		ft_puts(s);
		i += l;
	}
	return(i);
}


int		ft_str_width(char *s, t_flags flags, int l)
{
	int i;
	int k;

	i = 0;
	k = 0;

	if (flags.minus == 1)
	{
		if (flags.prec != -1 && flags.prec < l)
		{
			while (flags.prec-- > 0)
				i = ft_putchar(s[k++]);
		}
		else
			i += ft_puts(s);
	}
	if (flags.prec != - 1 && flags.prec < l)
		while (flags.width-- > flags.prec)
			i += ft_putchar(' ');
	else
		while (flags.width-- > l)
			i += ft_putchar(' ');
	if (flags.minus == 0)
	{
		if (flags.prec != -1 && flags.prec < l)
		{
			while (flags.prec-- > 0)
				i += ft_putchar(s[k++]);
		}
		else
			i += ft_puts(s);
	}
	return(i);
}

int 	ft_printstr(va_list ap, t_flags flags)
{
	int i;
	char *s;
	int len;

	i =  0;
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (flags.width > 0)
		i += ft_str_width(s, flags, len);
	else if (flags.prec > - 1)
		i += ft_str_prec(s, flags, len);
	else
		i += ft_puts(s);
	return(i);
}














