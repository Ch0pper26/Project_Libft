/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lstdc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:48:11 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/25 14:45:45 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_lstdc	*ft_create_str_lstdc(char **data, int nb_elem)
{
	t_lstdc	*new;
	void	**tab;

	tab = ft_stovv(data);
	new = ft_create_lstdc(nb_elem, tab, 's');
	free(tab);
	return (new);
}

void	ft_add_str(t_lstdc **lstdc, char *elem, int index)
{
	char	**tmp;

	tmp = malloc(sizeof(char *));
	*tmp = elem;
	ft_add_index(lstdc, tmp, index);
}

char	*ft_get_str(t_lstdc **lstdc, int index)
{
	void	*data;

	data = ft_get_data(lstdc, index);
	return (*((char **)data));
}

char	**ft_get_strs(t_lstdc **lstdc, int *index, int nb_elem)
{
	char	**tab;
	int		i;

	i = 0;
	if (nb_elem < 1)
		return (NULL);
	if (index[0] == -2)
	{
		nb_elem = ft_get_len_lstdc(lstdc);
		tab = malloc(sizeof(char *) * nb_elem);
		while (i < nb_elem)
		{
			tab[i] = ft_get_str(lstdc, i);
			i++;
		}
		return (tab);
	}
	tab = malloc(sizeof(char *) * nb_elem);
	while (i < nb_elem)
	{
		tab[i] = ft_get_str(lstdc, index[i]);
		i++;
	}
	return (tab);
}

char	*ft_change_str(t_lstdc **lstdc, char *data, int index)
{
	char	*content;
	t_lstdc	*elem;
	char	**tmp;

	tmp = malloc(sizeof(char *));
	*tmp = data;
	elem = *lstdc;
	ft_go_to(&elem, index);
	content = ft_get_str(lstdc, index);
	free(elem->data);
	elem->data = tmp;
	return (content);
}
