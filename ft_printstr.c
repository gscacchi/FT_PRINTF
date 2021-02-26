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

int 	ft_stringcases(t_flags flags, char *s, int len, int k)
{
	int i;

	i = 0;
	if (flags.minus == 1)
	{
		while (i < len)
			ft_putchar(s[i++]);
		while (i < flags.width)
		{
			i++;
			ft_putchar(' ');
		}
	}
	else
	{
		while (i < (flags.width - len))
		{
			i++;
			ft_putchar(' ');
		}
		while (len--)
			i += ft_putchar(s[k++]);
	}
	return(i);
}

int 	ft_printstr(va_list ap, t_flags flags)
{
	char *s;
	int len;
	int k;

	if (flags.prec < 0 && flags.prec != -1)
		flags.prec = -1;
	k = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = (flags.prec < ft_strlen(s) && flags.prec != -1) ? flags.prec : ft_strlen(s);
	return(ft_stringcases(flags, s, len, k));
}
