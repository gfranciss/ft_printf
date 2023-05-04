/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:03 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/04 15:48:48 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return(i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 1;
	if (nbr <= INT_MAX && nbr >= INT_MIN)
	{
		if (nbr < 0)
		{
			if (nbr == INT_MIN)
				return (ft_putstr("-2147483648"));
			ft_putchar('-');
			nbr *= -1;
		}
		else if (nbr > 9)
		{
			ft_putnbr(nbr / 10);
			ft_putnbr(nbr % 10);
		}
		else
			ft_putchar(nbr + '0');
	}
		if (nbr >= 10)
		{
			while (nbr / i > 9)
			{
				i *= 10;
				i++;
			}
		}
	return (i);
}

int	ft_putunnbr(unsigned int nbr)
{
	unsigned int i;
	
	i = 1;
	if (nbr > 9)
	{
		ft_putunnbr(nbr / 10);
		ft_putunnbr(nbr % 10);
	}
	else 
		ft_putchar(nbr + '0');
	if (nbr >= 10)
		while (nbr / i > 9)
		{
			i *= 10;
			i++;
		}
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
		ft_putnbr_hx(nbr / 16, caps);
	i += ft_putchar(hexadecimal[nbr % 16]);

	return (i);
}
