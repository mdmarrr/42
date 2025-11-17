/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/17 10:38:37 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
    printf("Probando en stdout:\n");
    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);

    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Error al abrir archivo");
        return 1;
    }

    ft_putnbr_fd(987654321, fd);
    write(fd, "\n", 1);

    ft_putnbr_fd(-2147483648, fd);
    write(fd, "\n", 1);

    close(fd);

    printf("Se han escrito números en test_output.txt.\n");

    return 0;
}
*/