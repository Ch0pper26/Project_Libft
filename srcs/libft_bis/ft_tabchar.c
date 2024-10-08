/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:20:17 by eblondee          #+#    #+#             */
/*   Updated: 2022/09/28 16:20:50 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	**ft_realloc_str(char **tab, char *elem, int index)
{
	int		len;
	char	**new_tab;

	len = ft_len_tabchar(tab);
	new_tab = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (tab[len] && len != index)
	{
		new_tab[len] = tab[len];
		len++;
	}
	new_tab[len] = ft_strdup(elem);
	while (tab[len])
	{
		len++;
		new_tab[len] = tab[len - 1];
	}
	new_tab[len + 1] = NULL;
	free(tab);
	return (new_tab);
}

char	**ft_supp_elem_tabchar(char **tab, int index)
{
	int		len;
	char	**new_tab;

	if (tab[0] == NULL)
		return (tab);
	len = ft_len_tabchar(tab);
	new_tab = malloc(sizeof(char *) * (len - 1));
	len = -1;
	if (index == -1)
	{
		while (tab[++len + 1])
			new_tab[len] = tab[len];
		new_tab[len] = NULL;
		free(tab[len]);
		free(tab);
		return (new_tab);
	}
	while (tab[++len] && len != index)
		new_tab[len] = tab[len];
	free(tab[len]);
	while (tab[++len] != NULL)
		new_tab[len - 1] = tab[len];
	new_tab[len - 1] = NULL;
	free(tab);
	return (new_tab);
}

char	**ft_merge_tabchar(char **tab1, char **tab2, char option)
{
	int	i;

	i = 0;
	while (tab2[i] != NULL)
	{
		tab1 = ft_realloc_str(tab1, tab2[i], -1);
		i++;
	}
	if (option == 'f')
		ft_free_tabchar(tab2);
	return (tab1);
}

char	**ft_copy_tabchar(char **tab)
{
	int		i;
	int		size;
	char	**copy;

	i = 0;
	size = ft_len_tabchar(tab);
	copy = malloc(sizeof(char *) * size);
	while (tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
