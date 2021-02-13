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

/*GESTIRE CASO DI FLAGS.PREC && FLAGS.WIDTH INSIEME*/

int		ft_str_width(char *s, t_flags flags, int l)
{
	int i;

	i = 0;
	if (flags.minus == 1)
		ft_puts(s);
	while(flags.width-- > l)
	{
		ft_putchar(' ');
		i++;
	}
	if (flags.minus == 0)
		ft_puts(s);
	return(l);
}

int		ft_str_prec(char *s, t_flags flags, int l)
{
	int k;

	k = 0;
	if (flags.prec < l)
	{
		while (flags.prec++ < l)
			ft_putchar(s[k++]);
	}
	else if (flags.prec >= l)
	{
		ft_puts(s);
		k = l;
	}
	return(k);
}

int		ft_printstr(va_list ap, t_flags flags)
{
	int i;
	char *s;
	int len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);

	if (flags.width > 0)
		i = ft_str_width(s, flags, len);
	else if (flags.prec > 0)
		i = ft_str_prec(s, flags, len);
	else
		ft_puts(s);
	return(i);

}
