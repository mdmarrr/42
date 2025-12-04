/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/12/04 12:57:00 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(((long)va_arg(args, int)), 10);
	else if (specifier == 'u')
		count += ft_print_nbr(va_arg(args, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_nbr(va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_print_nbr_caps(va_arg(args, unsigned int), 16);
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}
