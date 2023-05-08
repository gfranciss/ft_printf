/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:00:29 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/08 13:05:19 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunlong_nbr_hx(unsigned long nbr)
{
	int		i;
	char	hexadecimal[16];

	i = 0;
	ft_strcpy(hexadecimal, "0123456789abcdef");
	if (nbr >= 16)
		i += ft_putunlong_nbr_hx(nbr / 16);
	i += ft_putchar(hexadecimal[nbr % 16]);
	return (i);
}

int	ft_putptr(unsigned long nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
	{
		i = write(1, "(nil)", 5);
		return (i);
	}
	return (ft_putstr("0x") + ft_putunlong_nbr_hx(nbr));
}
