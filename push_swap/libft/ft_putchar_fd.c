/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 17:04:25 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;

	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	ft_putchar_fd('c', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}
*/