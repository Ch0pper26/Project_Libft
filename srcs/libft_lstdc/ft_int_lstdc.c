/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstdc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:55:03 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:45:30 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_lstdc	*ft_create_int_lstdc(int nb_elem, int *data)
{
	t_lstdc	*new;
	void	**tab;

	tab = ft_itovv(data);
	new = ft_create_lstdc(nb_elem, tab, 'i');
	free(tab);
	return (new);
}

void	ft_add_int(t_lstdc **lstdc, int elem, int index)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	*tmp = elem;
	ft_add_index(lstdc, tmp, index);
}

int	ft_get_int(t_lstdc **lstdc, int index)
{
	void	*data;

	data = ft_get_data(lstdc, index);
	return (*((int *)data));
}

int	*ft_get_ints(t_lstdc **lstdc, int *index, int nb_elem)
{
	int	*tab;
	int	i;

	i = 0;
	if (nb_elem < 1)
		return (NULL);
	if (index[0] == -2)
	{
		nb_elem = ft_get_len_lstdc(lstdc);
		tab = malloc(sizeof(int) * nb_elem);
		while (i < nb_elem)
		{
			tab[i] = ft_get_int(lstdc, i);
			i++;
		}
		return (tab);
	}
	tab = malloc(sizeof(int) * nb_elem);
	while (i < nb_elem)
	{
		tab[i] = ft_get_int(lstdc, index[i]);
		i++;
	}
	return (tab);
}

int	ft_change_int(t_lstdc **lstdc, int data, int index)
{
	int		content;
	t_lstdc	*elem;
	int		*tmp;

	tmp = malloc(sizeof(int));
	*tmp = data;
	elem = *lstdc;
	ft_go_to(&elem, index);
	content = ft_get_int(lstdc, index);
	free(elem->data);
	elem->data = tmp;
	return (content);
}
