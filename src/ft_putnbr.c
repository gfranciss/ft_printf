/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:58:38 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/08 12:24:11 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
