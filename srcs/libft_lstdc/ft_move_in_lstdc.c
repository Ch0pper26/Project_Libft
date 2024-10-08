/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_lstdc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:55:52 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/21 14:40:56 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_move_one(t_lstdc **lstdc)
{
	if (!lstdc || !(*lstdc))
		return ;
	if ((*lstdc)->next)
		(*lstdc) = (*lstdc)->next;
}

void	ft_move_lstdc(t_lstdc **lstdc, int move)
{
	int	i;

	i = 0;
	if (!lstdc || !(*lstdc))
		return ;
	while (i < move)
	{
		ft_move_one(lstdc);
		i++;
	}
}

void	ft_back_one(t_lstdc **lstdc)
{
	if (!lstdc || !(*lstdc))
		return ;
	if ((*lstdc)->prev)
		(*lstdc) = (*lstdc)->prev;
}

void	ft_back_lstdc(t_lstdc **lstdc, int back)
{
	int	i;

	i = 0;
	if (!lstdc || !(*lstdc))
		return ;
	while (i < back)
	{
		ft_back_one(lstdc);
		i++;
	}
}

void	ft_go_to(t_lstdc **lstdc, int where)
{
	if (!lstdc || !(*lstdc))
		return ;
	if (where == -1)
		while ((*lstdc)->next)
			(*lstdc) = (*lstdc)->next;
	else if (where == 0)
		while ((*lstdc)->prev)
			(*lstdc) = (*lstdc)->prev;
	else if (where > 0 && (*lstdc)->index < where)
		while ((*lstdc)->next && (*lstdc)->index != where)
			(*lstdc) = (*lstdc)->next;
	else if (where > 0 && (*lstdc)->index > where)
		while ((*lstdc)->prev && (*lstdc)->index != where)
			(*lstdc) = (*lstdc)->prev;
}
