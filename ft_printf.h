/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:50:09 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/04 12:21:26 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putunnbr(unsigned int nbr);

#endif
