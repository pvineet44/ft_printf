/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:43:42 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 16:11:13 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convert_to_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char			*reverse(char *str, char c)
{
	int			len;
	char		*rev;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = str[0];
	if (!(rev = malloc(sizeof(char) * (len + 1 + 2))))
		return (NULL);
	if (c == 'p' && (i = i + 2))
	{
		j = j + 2;
		rev[0] = '0';
		rev[1] = 'x';
	}
	while (i - j < len)
	{
		rev[i] = str[len - i + j];
		i++;
	}
	rev[i] = '\0';
	ft_free(str);
	if (c == 'X')
		return (convert_to_uppercase(rev));
	return (rev);
}

char			*decimal_to_hex(unsigned int decimal, char c)
{
	unsigned long	quotient;
	unsigned long	remainder;
	char			*str;
	int				i;


	i = 1;
	str = (char *)malloc(sizeof(char) * 20);
	if (str == NULL)
		return (0);
	quotient = 1;
	remainder = 0;
	while (quotient > 0)
	{
		quotient = decimal / 16;
		remainder = decimal % 16;
		if (remainder > 9)
			remainder = remainder + 87;
		else
			remainder = remainder + '0';
		decimal = quotient;
		str[i] = remainder;
		i++;
	}
	str[0] = (i - 1);
	return (reverse(str, c));
}
