/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:49:23 by gscala            #+#    #+#             */
/*   Updated: 2021/02/11 10:49:24 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int 	ft_strlen(char *c)
{
	int i;

	i = 0;
	while(c[i])
		i++;
	return(i);
}

void	ft_puts(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}


int 	ft_check(int c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return(1);
	if (c == 'X' || c == 's' || c == 'p' || c == 'c' )
		return(1);
	return(0);
}

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	unsigned char x;

	x = (unsigned char)c;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_stampaprimadellapercentuale(const char *f)
{
	int i;

	i = 0;
	while(f[i] != '%' && f[i])
	{
		ft_putchar(f[i]);
		i++;
	}
}

int 	ft_count(const char *format)
{
	int i;

	i = 0;
	while (format[i] != '%' && format[i])
		i++;
	return(i);
}


t_flags		ft_init_flags(const char *format)
{
	int i;
	t_flags		flags;

	i = ft_count(format);
	flags.prec = - 1;
	flags.minus = 0;
	flags.width = 0;
	flags.type = 0;
	flags.zero = 0;
	flags.i = i + 1;


	return (flags);
}


t_flags 	ft_init_width(t_flags flags, const char *format, va_list ap)
{
	if (format[flags.i] == '*')
	{
		flags.width = va_arg(ap, int);
		if (flags.width < 0)
		{
			flags.minus = 1;
			flags.width = -flags.width;
		}
		flags.i++;
	}
	else if (ft_isdigit(format[flags.i]))
		while (ft_isdigit(format[flags.i]))
			flags.width = flags.width * 10 + ((int)(format[flags.i++] - 48));
	//va_end(ap);
	return(flags);	
}


t_flags		ft_init_precision(t_flags flags, const char *format, va_list ap)
{
	flags.prec = 0;
	flags.i++;
	if (format[flags.i] == '*')
	{
		flags.prec = va_arg(ap, int);
		if (flags.prec < 0)
			flags.prec = -flags.prec;
		flags.i++;
	}
	else if (ft_isdigit(format[flags.i]))
		while (ft_isdigit(format[flags.i]))
			flags.prec = flags.prec * 10 + ((int)(format[flags.i++] - 48));
	//va_end(ap);
	return(flags);
}


t_flags 	ft_parsing(const char *format, t_flags flags, va_list ap)
{
	flags = ft_init_flags(format);

	while (format[flags.i] == '-' || format[flags.i] == '0')
	{
		if (format[flags.i] == '-')
			flags.minus = 1;
		if (format[flags.i] == '0')
			flags.zero = 1;
		flags.i++;
	}
	if (format[flags.i] == '*' || ft_isdigit(format[flags.i]))
		flags = ft_init_width(flags, format, ap);
	if (format[flags.i] == '.' && (format[flags.i + 1] == '*' || ft_isdigit(format[flags.i + 1])))
		flags= ft_init_precision(flags, format, ap);
	if (format[flags.i] == '.' && format[flags.i + 1])
		flags = ft_init_precision(flags, format, ap);
	else
		while (!ft_isalpha(format[flags.i]))
			flags.i++;
	flags.type = format[flags.i];

	return(flags);
}



int 	ft_printf(const char *format, ...)
{
	int n;
	t_flags flags;

	va_list ap;

	va_start(ap, format);
	flags = ft_init_flags(format);
	ft_stampaprimadellapercentuale(format);
	flags = ft_parsing(format, flags, ap);
	n = flags.i;
	/*n = flags.i;
	printf("%d", n);
	return(0);*/

	if (flags.type == 'd' || flags.type == 'i')
		n += ft_printint(ap, flags);
	if (flags.type == 'x')
		n += ft_x(ap);
	if (flags.type == 's')
		n += ft_printstr(ap, flags);
	/*printf("type: %c\n", flags.type);
	printf("minus: %d\n", flags.minus);
	printf("zero: %d\n", flags.zero);
	printf("prec: %d\n", flags.prec);
	printf("width: %d\n", flags.width);


	n = va_arg(ap, int);

	//ft_putnbr(n);


	va_end(ap);*/

	return(n);
}

int 	main()
{
	//ft_printf("%*d", 12, 2);


	//ft_printf(f, 12);


	ft_printf("fakeprint:%.*s", 2, "ammo");
	write(1, "\n", 1);

	printf("realprint:%.*s", 2, "ammo");
	
}


























