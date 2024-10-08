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

int	ft_is_unsigned_int(char *num)
{
	int			i;
	long long	nb;

	i = 0;
	while (num[i])
	{
		if ((ft_isdigit(num[i]) == 0))
			return (ft_print_error("Arguments isn't a unsigned int"));
		i++;
	}
	nb = ft_atoll(num);
	if (nb < 0 || nb > 2147483647)
		return (ft_print_error("Arguments isn't between 0 and MAX_INT"));
	return (0);
}

int	ft_is_int(char *num)
{
	int			i;
	long long	nb;

	i = 0;
	while (num[i])
	{
		if ((ft_isdigit(num[i]) == 0))
			return (ft_print_error("Arguments isn't a unsigned int"));
		i++;
	}
	nb = ft_atoll(num);
	if (nb < 0 || nb > 2147483647)
		return (ft_print_error("Arguments isn't between 0 and MAX_INT"));
	return (0);
}
