/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:36:56 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 14:18:16 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int		check_sign(char *str)
{
	int sign;
	int i;

	i = 0;
	sign = 0;
	while (!(str[i] > '0' && str[i] < '9'))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (sign % 2 == 0)
		return (0);
	return (1);
}

static	int		check_str(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (!(str[i] == '-' || str[i] == '+'))
		{
			if (!(str[i] == ' ' || (str[i] > 8 && str[i] < 14)) ||
				((str[i] == ' ' || (str[i] > 8 && str[i] < 14))
				&& (str[i - 1] == '-' || str[i - 1] == '+')))
			{
				return (-1);
			}
		}
		i++;
	}
	return (i);
}

static int		ret_num(char *str, int sign)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-1 * num);
	return (num);
}

int				ft_atoi(char *str)
{
	int j;
	int num;
	int sign;

	j = 0;
	num = 0;
	sign = 0;
	j = check_str(str);
	if (j > -1)
	{
		sign = check_sign(str);
		num = ret_num(&str[j], sign);
	}
	return (num);
}
