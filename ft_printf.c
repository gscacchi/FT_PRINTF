/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:49:23 by gscala            #+#    #+#             */
/*   Updated: 2021/02/18 15:40:00 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printpercent2(t_flags *flags, int count, char c)
{
	if (flags->minus == 1 || flags->zero == 1)
	{
		if (flags->minus == 0)
		{
			count += ft_print_zero(flags->width - 1);
			count += ft_putchar(c);
		}
		else
		{
			count += ft_putchar(c);
			count += ft_print_space(flags->width - 1);
		}
	}
	else
	{
		count += ft_print_space(flags->width - 1);
		count += ft_putchar(c);
	}
	return (count);
}

int ft_printpercent(t_flags *flags)
{
	int 	count;
	char 	c;

	c = '%';
	count = 0;
	if (flags->width > 1)
		count += ft_printpercent2(flags, count, c);
	else
		count += ft_putchar(c);
	return (count);
}

int 	ft_puts2(char *s, int c)
{
	int i;
	
	if (!*s)
		return(0);
	i = 0;
	while (i < c)
	{
		ft_putchar(s[i]);
		i++;
	}
	return(i);
}

int 	ft_print_zero(int n)
{
	int i;

	i = 0;
	while(n--)
	{
		ft_putchar('0');
		i++;
	}
	return(i);
}

int 	ft_print_space(int n)
{
	int i;

	i = 0;;
	while(n--)
	{
		ft_putchar(' ');
		i++;
	}
	return(i);
}

int 	ft_strlen(char *c)
{
	int i;

	i = 0;
	while(c[i] != 0)
		i++;
	return(i);
}

int 	ft_puts(char *s)
{
	int i;
	if (!*s)
		return(0);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return(i);
}

int  ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
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
	if (c == 'X' || c == 's' || c == 'p' || c == 'c' || c =='%')
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


t_flags		ft_init_flags(int i)
{
	t_flags		flags;

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
		flags.i++;
	}
	else if (ft_isdigit(format[flags.i]))
		while (ft_isdigit(format[flags.i]))
			flags.prec = flags.prec * 10 + ((int)(format[flags.i++] - 48));
	return(flags);
}


t_flags 	ft_parsing(const char *format, t_flags flags, va_list ap)
{
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
		while (!ft_check(format[flags.i]))
			flags.i++;
	flags.type = format[flags.i];
	return(flags);
}

int 	ft_checkprec(const char *f, int j)
{
	if (f[j] == '*' || f[j] == '-' || ft_isdigit(f[j]))
	{
		if (f[j] == '*')
			j++;
		else if (f[j] == '-' && ft_isdigit(f[j + 1]))
		{
			j++;
			while (ft_isdigit(f[j]))
				j++;
		}
		else if (ft_isdigit(f[j]))
			while (ft_isdigit(f[j]))
				j++;
	}
	return (j);
}


int 	ft_checkformat(const char *f, int i)
{
	int j;

	j = i + 1;
	while (f[j] == '-' || f[j] == '0')
		j++;
	if (f[j] == '*' || ft_isdigit(f[j]))
	{
		if (f[j] == '*')
			j++;
		else
			while (ft_isdigit(f[j]))
				j++;
	}
	if (f[j] == '.')
	{
		j++;
		j = ft_checkprec(f, j);
	}
	if (ft_check(f[j]))
		return(j + 1);
	return(0);
}


int 	ft_tipo(t_flags flags, va_list ap)
{
	int n;

	n = 0;
	if (flags.type == 'd' || flags.type == 'i')
		n += ft_printint(ap, flags);
	if (flags.type == 'x' || flags.type == 'X')
		n += ft_x(ap, flags);
	if (flags.type == 's')
		n += ft_printstr(ap, flags);
	if (flags.type == 'c')
		n += ft_printchar(ap, flags);
	if (flags.type == 'p')
		n += ft_printpoint(ap, flags);
	if (flags.type == 'u')
		n += ft_printu(ap, flags);
	if (flags.type == '%')
		n += ft_printpercent(&flags);

	return (n);
}

int 	ft_printf(const char *format, ...)
{
	int n;
	int i;
	t_flags flags;
	va_list ap;

	va_start(ap, format);
	n = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_checkformat(format, i))
		{
			flags = ft_init_flags(i);
			flags = ft_parsing(format, flags, ap);
			n += ft_tipo(flags, ap);
			i = ft_checkformat(format, i);
		}
		else if (!format[i])
			break;
		else
			n += ft_putchar(format[i++]);
	}
	va_end (ap);
	return (n);
}


/*
int 	main()
{
	//ft_printf("%*d", 12, 2);


	//ft_printf(f, 12);
	//printf("%d %s\n", 12, "ciao");

	//ft_printf("%d %s", 12, "ciao");
	ft_printf("%010.*i", -2, 8);
	//ft_printf("%10.5s", "abcd");
	//printf("return: %d\n", ft_printf("mioo: %d", 1234567));
	//printf("return: %d\n", ft_printf("vero: %d", 1234567));
	//printf("return: %d\n", ft_printf("ft: %010d %10s\n", 123, "porcodio"));
	//printf("return: %d\n", printf("pr: %010d %10s\n", 123, "porcodio"));
	//printf("returnmio: %d\n", ft_printf("mio: %015.27x\n", 17244));
	//printf("return %d\n", ft_printf("mio %-.3s\n", "aereo"));
	//printf("return %d\n",printf("tuo %-.3s\n", "aereo"));
	//printf("returntuo: %d\n", printf("ver: %015.27x", 17244));

	//ft_printf("mio: %10.5d\n", 1724);
	//printf("ver: %10.5d", 1724);

	//printf("return: %d\n", ft_printf("%d ablo %s\n", 123, "abcd"));
	//printf("return: %d", printf("%d ablo %s\n", 123, "abcd"));
	
	

	//printf("%d", 123456789);
	//printf("return: %d\n", ft_printf("fake:%-.10d\n", 123));
	
	//printf("return: %d\n", printf("real:%-.10d\n", 123));
	
}
*/