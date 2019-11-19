/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:47 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 16:16:50 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nbr_len(unsigned nbr)
{
	int		i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr = (nbr / 10);
		i++;
	}
	return (i);
}

char			*ft_uint_itoa(unsigned int nbr)
{
	unsigned int		length;
	unsigned int		i;
	char				*result;

	i = 0;
	length = ft_nbr_len(nbr);
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (++i <= length)
	{
		result[length - i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	result[length] = '\0';
	return (result);
}
