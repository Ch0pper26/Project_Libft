/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_lstdc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:47:03 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/26 17:41:26 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_merge_lstdc(t_lstdc **lstdc1, t_lstdc **lstdc2)
{
	t_lstdc	*start;
	t_lstdc	*end;

	start = *lstdc1;
	end = *lstdc2;
	ft_go_to(&start, -1);
	ft_go_to(&end, 0);
	start->next = end;
	end->prev = start;
	ft_fix_index(lstdc1, 1);
}

/*void	ft_merge_one_lstdc(t_lstdc **lstdc1, t_lstdc **lstdc2)
	{
	t_lstdc	*start;
	t_lstdc	*end;
	int		len_start;
	int		len_end;
	int		i;

	i = 1;
	start = *lstdc1;
	end = *lstdc2;
	len_start = ft_get_len_lstdc(lstdc1);
	len_end = ft_get_len_lstdc(lstdc2);
	ft_go_to(&start, 0);
	ft_go_to(&end, 0);
	while (len_end)
	{
		
	}
	ft_fix_index(lstdc1, 1);
}*/
