/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:00:44 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/14 13:11:03 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	str = (char *)s;
	while (i < (len + 1))
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
