/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anything_to_void.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:55:34 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/20 14:01:51 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	**ft_itovv(int *nb)
{
	void	**elem;

	elem = malloc(sizeof(void *));
	*elem = nb;
	return (elem);
}

void	**ft_ctovv(char *c)
{
	void	**elem;

	elem = malloc(sizeof(void *));
	*elem = c;
	return (elem);
}

void	**ft_stovv(char **tab)
{
	void	**elem;

	elem = malloc(sizeof(void *));
	*elem = tab;
	return (elem);
}
