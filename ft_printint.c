/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:45:02 by gscala            #+#    #+#             */
/*   Updated: 2021/02/12 11:45:23 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int			ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
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
	if (sign == -1)
		c[0] = '-';
	return (c);
}




int 	ft_int_width(t_flags flags, char *c, int len)
{
	int i;

	i = 0;
	if (flags.zero == 1)
	{
		i+=ft_print_zero(flags.width - len);
		i+=ft_puts(c);
	}
	else
	{
		if (flags.minus == 1)
			i+=ft_puts(c);
		i+=ft_print_space(flags.width - len);
		if (flags.minus == 0)
			i+=ft_puts(c);
	}
	return(i);
}

int 	ft_int_widthandprec(t_flags flags, char *c, int len)
{
	int i;

	i = 0;
	if (flags.minus == 1)
	{
		i+=ft_print_zero(flags.prec - len);
		i+=ft_puts(c);
		i+=ft_print_space(flags.width - flags.prec);
	}
	else
	{
		i+=ft_print_space(flags.width - flags.prec);
		i+=ft_print_zero(flags.prec - len);
		i+=ft_puts(c);
	}
	return(i);
}

int		ft_printint(va_list ap, t_flags flags)
{
	int i;
	int n;
	int len;
	char *c;

	i = 0;
	n = va_arg(ap, int);
	c = ft_itoa(n);
	len = ft_strlen(c);

	if (flags.width > len && flags.prec >= len)
		i = ft_int_widthandprec(flags, c, len);
	else if (flags.width > len)
		i = ft_int_width(flags, c, len);
	else if (flags.prec > 0 && flags.width == 0)
	{
			i+=ft_print_zero(flags.prec - len);
		i+=ft_puts(c);
	}
	else 
		i+=ft_puts(c);
	return(i);
}
	









