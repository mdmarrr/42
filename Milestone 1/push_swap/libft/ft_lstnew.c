/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/20 10:06:33 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*
#include <stdio.h>
int main(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("Primer nodo");
	node2 = ft_lstnew("Segundo nodo");
	if (!node1)
	{
		printf("Error al crear node1\n");
		return (1);
	}
	if (!node2)
	{
		printf("Error al crear node2\n");
		free(node1);
		return (1);
	}
	node1->next = node2;
	printf("Contenido: %s\n", (char *)node1->content);
	if (node1->next == NULL)
		printf("NULL\n");
	else
		printf("no NULL\n");
	printf("Contenido: %s\n", (char *)node2->content);
	if (node2->next == NULL)
		printf("NULL\n");
	else
		printf("no NULL\n");
	free(node1);
	free(node2);
	return (0);
}
*/