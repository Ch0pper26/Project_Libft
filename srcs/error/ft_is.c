/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:47:24 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/08 16:47:30 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_is_int(char *num)
{
	int			i;
	long long	nb;

	i = 0;
	while (num[i])
	{
		if ((ft_isdigit(num[i]) == 0))
			return (ft_print_error("Arguments weren't a unsigned int"));
		i++;
	}
	nb = ft_atoll(num);
	if (nb < 1 || nb > 2147483647)
		return (ft_print_error("Arguments weren't between 1 and MAX_INT"));
	return (0);
}
