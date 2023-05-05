/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:03 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/05 16:18:52 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	int i;

	i = write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == 0)
	{
		i = write(1, "(null)", 6);
		return(i);
	}
	while (*s != '\0')
	{
		i += write(1, s, 1);
		s++;
	}
	return(i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == INT_MIN)
		i += write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			i += ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= 10)
			i += ft_putnbr(nbr / 10);
		i += ft_putchar((nbr % 10) + '0');
	}
	return (i);
}

int	ft_putunnbr(unsigned int nbr)
{
	unsigned int i;
	
	i = 0;
	if (nbr >= 10)
		i += ft_putunnbr(nbr /10);
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}
int ft_putnbr_hx(unsigned int nbr, int caps)
{
	int		i;
	char	hexadecimal[16];
	
	i = 0;
	if (caps == 0)
		ft_strcpy(hexadecimal, "0123456789abcdef");
	else
		ft_strcpy(hexadecimal, "0123456789ABCDEF");
	if(nbr >= 16)
		i += ft_putnbr_hx(nbr / 16, caps);
	i += ft_putchar(hexadecimal[nbr % 16]);

	return (i);
}

int	ft_putptr(unsigned long nbr)
{
	int		i;
	char	hexadecimal[16];

	i = 0;
	ft_strcpy(hexadecimal, "0123456789abcdef");
	if (nbr == 0)
	{
		i = write(1, "(nil)", 5);
		return(i);
	}
	if (nbr >= 16)
		i += ft_putptr(nbr / 16);
	i += ft_putchar(hexadecimal[nbr % 16]);
	return (i);
}
