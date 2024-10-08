/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lstdc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:15:05 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:45:08 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_get_len_lstdc(t_lstdc **lstdc)
{
	int		len;
	t_lstdc	*elem;

	len = 0;
	if (!lstdc || !(*lstdc))
		return (len);
	elem = *lstdc;
	ft_go_to(&elem, 0);
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}

void	*ft_get_data(t_lstdc **lstdc, int index)
{
	t_lstdc	*elem;

	elem = *lstdc;
	if (!lstdc || !(*lstdc))
		return (NULL);
	ft_go_to(&elem, index);
	return (elem->data);
}
