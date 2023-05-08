/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:58:22 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/08 12:24:53 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (*s != '\0')
	{
		i += write(1, s, 1);
		s++;
	}
	return (i);
}
