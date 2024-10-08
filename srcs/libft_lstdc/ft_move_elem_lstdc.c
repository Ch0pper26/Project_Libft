/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_elem_lstdc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:48:19 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 17:06:10 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_swap_data(t_lstdc **lstdc, int index_1, int index_2)
{
	void	*data_1;
	void	*data_2;
	t_lstdc	*l_1;
	t_lstdc	*l_2;

	l_1 = *lstdc;
	l_2 = *lstdc;
	ft_go_to(&l_1, index_1);
	ft_go_to(&l_2, index_2);
	data_1 = l_1->data;
	data_2 = l_2->data;
	l_2->data = data_1;
	l_1->data = data_2;
}
