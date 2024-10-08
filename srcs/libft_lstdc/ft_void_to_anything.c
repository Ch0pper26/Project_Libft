/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_to_anything.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:22:38 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/20 11:21:30 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	*ft_vvtoi(void **tab)
{
	int	*elem;

	elem = malloc(sizeof(int *));
	elem = (*(int **)tab);
	return (elem);
}

char	*ft_vvtoc(void **tab)
{
	char	*elem;

	elem = malloc(sizeof(char *));
	elem = (*(char **)tab);
	return (elem);
}

char	**ft_vvtos(void **tab)
{
	char	**elem;

	elem = malloc(sizeof(char **));
	elem = (*(char ***)tab);
	return (elem);
}
