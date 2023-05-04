/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:03 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/04 12:23:16 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (nbr > 9)
	{
		ft_putunnbr(nbr / 10);
		ft_putunnbr(nbr % 10);
	}
	else 
		ft_putchar(nbr + '0');
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
