/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:05:01 by gscala            #+#    #+#             */
/*   Updated: 2021/02/17 12:05:03 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_convert_x(char *exa)
{
	int i;

	i = 0;
	exa[i] = '0';
	exa[++i] = '1';
	exa[++i] = '2';
	exa[++i] = '3';
	exa[++i] = '4';
	exa[++i] = '5';
	exa[++i] = '6';
	exa[++i] = '7';
	exa[++i] = '8';
	exa[++i] = '9';
	exa[++i] = 'a';
	exa[++i] = 'b';
	exa[++i] = 'c';
	exa[++i] = 'd';
	exa[++i] = 'e';
	exa[++i] = 'f';
	exa[++i] = '\0';
	return(exa);
}

char 	*ft_convert_X(char *exa)
{
	int i;

	i = 0;
	exa[i] = '0';
	exa[++i] = '1';
	exa[++i] = '2';
	exa[++i] = '3';
	exa[++i] = '4';
	exa[++i] = '5';
	exa[++i] = '6';
	exa[++i] = '7';
	exa[++i] = '8';
	exa[++i] = '9';
	exa[++i] = 'A';
	exa[++i] = 'B';
	exa[++i] = 'C';
	exa[++i] = 'D';
	exa[++i] = 'E';
	exa[++i] = 'F';
	exa[++i] = '\0';
	return(exa);
}

char	*reverse(char *str)
{
	char *ris;
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (!(ris = malloc((sizeof(char)) * (len + 1))))
		return(NULL);
	while (len--)
		ris[i++] = str[len];
	ris[i] = 0;
	return(ris);
}

int 	ft_regxcase(t_flags flags, char *c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(c);
	if (flags.prec > flags.width && flags.prec > len)
	{
		i += ft_print_zero(flags.prec - len);
		i+= ft_puts(c);
	}
	else if (flags.width > len && flags.prec >= len)
		i = ft_int_widthandprec(flags, c, len);
	else if (flags.width > len)
		i = ft_int_width(flags, c, len);
	else if (flags.prec > len && flags.width == 0)
	{
			i += ft_print_zero(flags.prec - len);
		i+=ft_puts(c);
	}
	else 
		i+=ft_puts(c);
	return(i);
}

int 	ft_x(va_list ap, t_flags flags)
{
	int n;
	int resto;
	char ris[101];
	char exa[17];
	int i;

	resto = 0;
	n = va_arg(ap, int);
	if (flags.type == 'x')
		ft_convert_x(exa);
	if (flags.type == 'X')
		ft_convert_X(exa);
	i = 0;
	if (n == -1)
	{
		while(i < 8)
		{
			ris[i] = exa[15];
			i++;
		}
	}
	else if (n == 0 && flags.prec == -1)
	{
		ris[i] = '0';
		i++;
	}
	else
	{
		while (n > 0)
		{
			resto = n % 16;
			ris[i] = exa[resto];
			n = n / 16;
			i++;
		}
	}
	ris[i] = 0;
	i = - 1;
	i = ft_regxcase(flags, reverse(ris));
	return(i);
}

