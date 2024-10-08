/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:55:24 by eblondee          #+#    #+#             */
/*   Updated: 2022/09/29 10:15:23 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	**ft_splitters(char *str, char *splitters)
{
	int		i;
	int		j;
	char	*elem;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *));
	tab[0] = NULL;
	while (str[i])
	{
		while (str[i] && ft_is_in(str[i], splitters))
			i++;
		j = i;
		while (str[j] && ft_is_in(str[j], splitters) == 0)
			j++;
		elem = ft_substr(str, i, j - i);
		tab = ft_realloc_str(tab, elem, -1);
		free(elem);
		i = j;
	}
	return (tab);
}

int	ft_is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
