/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lstdc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:54:26 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:42:50 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_print_one(t_lstdc *lstdc, char type)
{
	if (!lstdc)
		return ;
	if (type == 'd' || type == 'i')
		ft_printf("%d, %d\n", lstdc->index,*(int *)lstdc->data);
	if (type == 'c')
		ft_printf("%d, %c\n", lstdc->index,*(char *)lstdc->data);
	if (type == 's')
		ft_printf("%d, %s\n", lstdc->index,*(char ***)lstdc->data);
}

void	ft_print_lstdc(t_lstdc **lstdc, char type)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	while (elem)
	{
		ft_print_one(elem, type);
		elem = elem->next;
	}
}

void	ft_rev_print_lstdc(t_lstdc **lstdc, char type)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	while (elem && elem->next)
		elem = elem->next;
	while (elem)
	{	
		ft_print_one(elem, type);
		elem = elem->prev;
	}
}

void	ft_print_one_lstdc(t_lstdc **lstdc, char type, int index)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	ft_go_to(&elem, index);
	ft_print_one(elem, type);
	elem = elem->next;
}

/*void	ft_print_lstdc(t_lstdc **lstdc, char type, int index)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	ft_go_to(&elem, index);
	while (elem)
	{
		ft_print_one(elem, type);
		elem = elem->next;
	}
}*/

void	ft_check_print(t_lstdc **lstdc, char type)
{
	ft_print_lstdc(lstdc, type);
	ft_printf("\n");
	ft_rev_print_lstdc(lstdc, type);
	ft_printf("\n");
}
