/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:59:22 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/08 12:19:58 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunnbr(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr >= 10)
		i += ft_putunnbr(nbr / 10);
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}
