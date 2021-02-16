/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:49:31 by gscala            #+#    #+#             */
/*   Updated: 2021/02/11 10:49:33 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_flags
{
	int prec;
	int minus;
	int width;
	char type;
	int zero;
	int i;
}					t_flags;

int 	ft_printf(const char *format, ...);
int 	ft_decimal(va_list ap);
int ft_x(va_list ap);
int	ft_puts(char *s);
int  ft_putchar(char c);
char *ft_arr(char *exa);
int len(char *str);
char *reverse(char *str);
t_flags 	ft_parsing(const char *format, t_flags flags, va_list ap);
t_flags		ft_init_precision(t_flags flags, const char *format, va_list ap);
t_flags 	ft_init_width(t_flags flags, const char *format, va_list ap);
t_flags		ft_init_flags(int i);
int 	ft_count(const char *format);
int 	ft_strlen(char *c);
void	ft_putnbr(int nb);
int		ft_printint(va_list ap, t_flags flags);
char		*ft_itoa(int n);
int			ft_len(long int nbr);
long int	ft_abs(long int nbr);
int		ft_printstr(va_list ap, t_flags flags);
int		ft_str_prec(char *s, t_flags flags, int l);
int		ft_str_width(char *s, t_flags flags, int l);
int 	ft_print_zero(int n);
int 	ft_print_space(int n);
int 	ft_printchar(va_list ap, t_flags flags);
int 	ft_putchar(char c);

#endif
