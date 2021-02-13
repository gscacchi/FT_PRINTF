/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:29:32 by gscala            #+#    #+#             */
/*   Updated: 2021/02/12 14:29:34 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_arr(char *exa)
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
    return (exa);
}

int len(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char *reverse(char *str)
{
	int lun = len(str);
	char *ris;
	ris = malloc(sizeof(char) * (len(str) + 1));
	int i = 0;
	while (lun--)
		ris[i++] = str[lun];
	ris[i] = '\0';
	return (ris);
}

int ft_x(va_list ap)
{
	int c;
    int i;
    int resto;
    char *ris;
    char exa[16]; 

    c = va_arg(ap, int);
    ris = malloc(sizeof(char) * 101);
    ft_arr(exa);
    i = 0;
    while(c != 0)
    {
        resto = c % 16;
        ris[i] = exa[resto];
        i++;
        c = c / 16;
    }
    ris[i] = '\0';
    ft_puts(reverse(ris));
    return (1);
}