/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:15:40 by gscala            #+#    #+#             */
/*   Updated: 2021/02/19 11:15:43 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *reverse1(char *str)
{
	char *ris;
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (!(ris = malloc((sizeof(char)) * (len + 3))))
		return(NULL);
	ris[i] = '0';
	i++;
	ris[i] = 'x';
	i++;
	while (len--)
		ris[i++] = str[len];
	ris[i] = 0;
	return(ris);
}

int ft_printpoint(va_list ap, t_flags flags)
{
	size_t p;
	int i;
	int resto;
	char exa[17];
	char ris[13];

	i = 0;
	resto = 0;
	p = va_arg(ap, size_t);
	ft_convert_x(exa);
	if (p == 0)
	{
		ris[i] = '0';
		i++;
	}
	
	else
	{
		while(p > 0)
		{
			resto = p % 16;
			ris[i++] = exa[resto];
			p = p / 16;
		}

	}
	ris[i] = '\0';

	i = ft_widthpoint(flags, reverse1(ris));
	return (i);

}

int	ft_widthpoint(t_flags flags, char *ris)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(ris);
	if (flags.width >= len && flags.minus == 0 && len >= 11)
	{
		i += ft_print_space(flags.width - len);
		i += ft_puts(ris);
	}
	else if (flags.width >= len && flags.minus == 1 && len >= 11)
	{
		i += ft_puts(ris);
		i += ft_print_space(flags.width - len);
	}
	else if(flags.width >= len && len < 11 && flags.prec == -1)
	{
		i += ft_print_space(flags.width - len);
		i += ft_puts(ris);
	}
	else if (flags.prec < len && flags.width >= len)
	{
		if (len == 3)
		{
			i += ft_print_space(flags.width - len + 1);
			i += ft_puts2(ris, (flags.prec + 2));
		}
		else
		{
			i += ft_print_space(flags.width - len);
			i += ft_puts(ris);
		}
		
	}
	else if (flags.prec < len && len < 11 && flags.prec != -1)
	{
		i += ft_puts2(ris, (flags.prec + 2));
	}
	else if (flags.width < len)
		i += ft_puts(ris);
	return (i);
}