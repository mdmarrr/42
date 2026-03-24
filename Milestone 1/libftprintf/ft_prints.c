/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/18 10:03:58 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
		return (ft_print_char('0'));
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		ft_print_char('-');
		n *= -1;
		count++;
	}
	if (n >= base)
	{
		count += ft_print_nbr(n / base, base);
	}
	count += ft_print_char(symbols[n % base]);
	return (count);
}

int	ft_print_nbr_caps(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_nbr_caps(n / base, base);
		return (count + ft_print_nbr_caps(n % base, base));
	}
	return (count);
}

int	ft_print_nbr_base(unsigned long long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n >= (unsigned long long)base)
		count += ft_print_nbr_base(n / base, base, symbols);
	count += ft_print_char(symbols[n % base]);
	return (count);
}

int	ft_print_pointer(void *pointer)
{
	unsigned long long	address;
	int					count;

	count = 0;
	address = (unsigned long long) pointer;
	if (pointer == NULL)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	count += ft_print_nbr_base(address, 16, "0123456789abcdef");
	return (count);
}
