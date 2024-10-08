/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_lstdc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:38:40 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 16:49:02 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_lstdc	*ft_check_index(t_lstdc **lstdc, int shift)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return (NULL);
	elem = *lstdc;
	if (!elem->prev && elem->index != 0)
		return (elem);
	while (elem->next)
	{
		if (elem->next->index == (elem->index + shift))
			elem = elem->next;
		else
			return (elem->next);
	}
	return (NULL);
}

void	ft_fix_index(t_lstdc **lstdc, int shift)
{
	t_lstdc	*elem;

	if (!lstdc || !(*lstdc))
		return ;
	elem = *lstdc;
	if (!elem->prev)
		elem->index = 0;
	while (elem->next)
	{
		if (elem->next->index == (elem->index + shift))
			elem = elem->next;
		else
		{
			elem = elem->next;
			elem->index = elem->prev->index + shift;
		}
	}
}
