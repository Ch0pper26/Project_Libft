/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lstdc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:15:14 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/22 17:51:41 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_lstdc	*ft_create_one(int index, void *data)
{
	t_lstdc	*lstdc;

	lstdc = malloc(sizeof(t_lstdc));
	lstdc->index = index;
	lstdc->data = data;
	lstdc->next = NULL;
	lstdc->prev = NULL;
	return (lstdc);
}

t_lstdc	*ft_create_lstdc(int nb_elem, void **data, char type)
{
	t_lstdc	*lstdc;
	t_lstdc	*end;
	int		i;

	i = -1;
	if (nb_elem == 0)
		return (NULL);
	lstdc = ft_create_one(-1, data[0]);
	if (type == 'd' || type == 'i')
		while (++i < nb_elem)
			ft_add_int(&lstdc, (*(int **)data)[i], -1);
	else if (type == 'c')
		while (++i < nb_elem)
			ft_add_char(&lstdc, (*(char **)data)[i], -1);
	else if (type == 's')
		while (++i < nb_elem)
			ft_add_str(&lstdc, (*(char ***)data)[i], -1);
	end = lstdc->next;
	free(lstdc);
	end->prev = NULL;
	return (end);
}
