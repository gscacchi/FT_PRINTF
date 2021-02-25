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

/*
void ft_becomingnull(char *s)
{
	char c[7];

	c[0] = '(';
	c[1] = 'n';
	c[2] = 'u';
	c[3] = 'l';
	c[4] = 'l';
	c[5] = ')';
	c[6] = 0;
	s = c;
}
*/

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


/*
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

int 	ft_isnull(char *s)
{
	if (s[0] == 'N' && s[1] == 'U' && s[2] == 'L' && s[3] == 'L')
		return(1);
	return (0);
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

char 	* ft_becomingnull()
{
	char c[7];
	int i;

	i = 0;

	c[0] = '(';
	c[1] = 'n';
	c[2] = 'u';
	c[3] = 'l';
	c[4] = 'l';
	c[5] = ')';
	c[6] = 0;

	return(c);

}


int 	ft_printnull(char *s, char l, t_flags flags)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (flags.minus == 1)
	{
		if (flags.prec < l && flags.prec > -1)
		{
			while (flags.prec--)
				i += ft_putchar(s[k++]);
		}
		else if (flags.prec == -1)
			i += ft_puts(s);
		if (flags.width > i)
		{
			while (flags.width > i)
				i += ft_putchar(' ');
		}
	}
	else
	{
		if (flags.prec > -1)
		{
			if (flags.width > (flags.prec))
			{
				while ((flags.width - (l - flags.prec) > i))
					i += ft_putchar(' ');
			}
			while (flags.prec--)
				i += ft_putchar(s[k++]);
		}
		else if (flags.width > l)
		{
				while(flags.width-- > l)
					i += ft_putchar(' ');
			i += ft_puts(s);
		}
		else
		 i += ft_puts(s);
	}
	return(i);
}

int 	ft_printnull(char *s, int l, t_flags flags)
{
	int i;

	i = 0;
	if (flags.prec >= l || flags.prec == - 1)
	{
		if (flags.minus == 1)
			i += ft_puts(s);
		if (flags.width > l)
		{
			while (flags.width-- > l)
				i += ft_putchar(' ');
		}
		if (flags.minus == 0)
			i += ft_puts(s);
	}
	else
	{
		if (flags.width > 0)
		{
			while (flags.width-- > 0)
				i += ft_putchar(' ');
		}
	}
	return (i);
}


int 	ft_width_and_prec_str(char *s, int len, t_flags flags)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (flags.minus == 1)
	{
		while (flags.prec-- > 0)
			i += ft_putchar(s[k++]);
		while (flags.width-- > k)
			i += ft_putchar(' ');
	}
	else
	{
		while (flags.width-- > flags.prec)
			i += ft_putchar(' ');
		while (flags.prec < len--)
			i += ft_putchar(s[k++]);
	}
	return (i);
}


int 	ft_printstr(va_list ap, t_flags flags)
{
	int i;
	char *s;
	int len;

	i = 0;
	s = va_arg(ap, char *);
	if (s != NULL)
		len = ft_strlen(s);
	if (s == NULL)
	{
		s = ft_becomingnull();
		i += ft_printnull(s, 6, flags);
	}
	//else if (flags.width > flags.prec && flags.prec != - 1 && flags.prec < len)
	//	i += ft_width_and_prec_str(s, len, flags);
	else if (flags.width > 0)
		i += ft_str_width(s, flags, len);
	else if (flags.prec > - 1)
		i += ft_str_prec(s, flags, len);
	else
		i += ft_puts(s);
	return(i);
}

*/











