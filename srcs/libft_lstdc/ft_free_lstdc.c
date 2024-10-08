/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lstdc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:51:00 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:42:04 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_free_lstdc(t_lstdc **lstdc)
{
	t_lstdc	*elem;
	t_lstdc	*next;

	if (!lstdc || !(*lstdc))
		return ;
	ft_go_to(lstdc, 0);
	elem = *lstdc;
	while (elem)
	{
		next = elem->next;
		free(elem->data);
		free(elem);
		elem = next;
	}
}

void	ft_destroy_link(t_lstdc **lstdc, int index)
{
	if (!lstdc || !(*lstdc))
		return ;
	ft_destroy_utils(lstdc, index);
	ft_fix_index(lstdc, 1);
}

void	ft_destroy_links(t_lstdc **lstdc, int *index, int lenght)
{
	int	i;

	i = 0;
	if (!lstdc || !(*lstdc))
		return ;
	while (i < lenght)
	{
		ft_destroy_utils(lstdc, index[i]);
		i++;
	}
	ft_fix_index(lstdc, 1);
}

void	ft_destroy_slot(t_lstdc **lstdc, int start, int end)
{
	if (!lstdc || !(*lstdc))
		return ;
	if (start > end || start < 0 || end < 0)
		return ;
	while (start <= end)
	{
		ft_destroy_utils(lstdc, start);
		start++;
	}
	ft_fix_index(lstdc, 1);
}

void	ft_destroy_utils(t_lstdc **lstdc, int index)
{
	t_lstdc	*elem[3];

	elem[0] = *lstdc;
	ft_go_to(&elem[0], index);
	if (index == -1 || elem[0]->index == index)
	{
		elem[1] = elem[0]->next;
		elem[2] = elem[0]->prev;
		if (elem[0]->index == (*lstdc)->index)
		{
			if (elem[2])
				(*lstdc) = elem[2];
			else if (elem[1])
				(*lstdc) = elem[1];
			else
				(*lstdc) = NULL;
		}
		free(elem[0]->data);
		free(elem[0]);
		if (elem[2])
			elem[2]->next = elem[1];
		if (elem[1])
			elem[1]->prev = elem[2];
	}
}
