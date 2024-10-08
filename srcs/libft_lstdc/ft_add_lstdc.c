/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lstdc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:44:50 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/26 17:42:59 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_add_front(t_lstdc **lstdc, void *data)
{
	t_lstdc	*new;

	if (!lstdc || !(*lstdc))
		return ;
	new = ft_create_one(0, data);
	new->next = *lstdc;
	new->prev = NULL;
	(*lstdc)->prev = new;
	*lstdc = new;
	ft_fix_index(lstdc, 1);
}

void	ft_add_back(t_lstdc **lstdc, void *data)
{
	t_lstdc	*new;
	t_lstdc	*end;

	if (!lstdc || !(*lstdc))
		return ;
	end = *lstdc;
	while (end->next)
		end = end->next;
	new = ft_create_one(end->index + 1, data);
	end->next = new;
	new->index = end->index + 1;
	new->prev = end;
}

void	ft_add_index(t_lstdc **lstdc, void *data, int index)
{
	t_lstdc	*elem;
	t_lstdc	*new;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	if (index > 0)
		ft_go_to(&elem, index - 1);
	else if (index == -1)
		return (ft_add_back(lstdc, data));
	else if (index == 0)
		return (ft_add_front(lstdc, data));
	new = ft_create_one(index, data);
	new->prev = elem;
	new->next = elem->next;
	if (elem->next)
		elem->next->prev = new;
	elem->next = new;
	ft_fix_index(lstdc, 1);
}

void	ft_add_elem(t_lstdc **lstdc, t_lstdc *elem, int index)
{
	t_lstdc	*tmp;

	tmp = *lstdc;
	ft_go_to(&tmp, index);
	if (index == -2)
	{
		ft_go_to(&tmp, -1);
		elem->next = NULL;
		elem->prev = tmp;
		tmp->next = elem;
		return (ft_fix_index(lstdc, 1));
	}
	if (tmp->prev)
	{
		elem->prev = tmp->prev;
		tmp->prev->next = elem;
	}
	else
	{
		(*lstdc) = elem;
		elem->prev = NULL;
	}
	tmp->prev = elem;
	elem->next = tmp;
	ft_fix_index(lstdc, 1);
}
