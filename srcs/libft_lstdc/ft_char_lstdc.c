/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_lstdc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:16:10 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:46:07 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_lstdc	*ft_create_char_lstdc(char *data, int nb_elem)
{
	t_lstdc	*new;
	void	**tab;

	tab = ft_ctovv(data);
	new = ft_create_lstdc(nb_elem, tab, 'c');
	free(tab);
	return (new);
}

void	ft_add_char(t_lstdc **lstdc, char elem, int index)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	*tmp = elem;
	ft_add_index(lstdc, tmp, index);
}

char	ft_get_char(t_lstdc **lstdc, int index)
{
	void	*data;

	data = ft_get_data(lstdc, index);
	return (*((char *)data));
}

char	*ft_get_chars(t_lstdc **lstdc, int *index, int nb_elem)
{
	char	*tab;
	int		i;

	i = 0;
	if (nb_elem < 1)
		return (NULL);
	if (index[0] == -2)
	{
		nb_elem = ft_get_len_lstdc(lstdc);
		tab = malloc(sizeof(char) * nb_elem);
		while (i < nb_elem)
		{
			tab[i] = ft_get_char(lstdc, i);
			i++;
		}
		return (tab);
	}
	tab = malloc(sizeof(char) * nb_elem);
	while (i < nb_elem)
	{
		tab[i] = ft_get_char(lstdc, index[i]);
		i++;
	}
	return (tab);
}

char	ft_change_char(t_lstdc **lstdc, char data, int index)
{
	char	content;
	t_lstdc	*elem;
	char	*tmp;

	tmp = malloc(sizeof(char));
	*tmp = data;
	elem = *lstdc;
	ft_go_to(&elem, index);
	content = ft_get_char(lstdc, index);
	free(elem->data);
	elem->data = tmp;
	return (content);
}
