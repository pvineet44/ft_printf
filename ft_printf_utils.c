/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:59:39 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 16:15:51 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_free(char *str)
{
	if (str == NULL)
		return (1);
	free(str);
	str = NULL;
	return (1);
}

char			*act_null_check(char *str)
{
	if (str)
		return (str);
	else
		return ("(null)");
}

int				act_custom_write(t_meta_print meta, char *str, int a, int b)
{
	int		i;
	char 	c;

	i = 0;
	c = ' ';
	if (meta.flag == '-')
		write(1, str, b);
	if (meta.flag == '0' && (meta.precision > b))
		c = '0';
	while (i < (a - b))
	{
		ft_putchar(c);
		i++;
	}
	if (meta.flag != '-')
		write(1, str, b);
	return (i + b);
}

t_meta_print	check_var_meta(t_meta_print meta, va_list ap)
{
	int flag_w;
	int flag_p;

	flag_w = 0;
	flag_p = 0;
	if (meta.width == -1 && (flag_w = flag_w + 1))
		meta.width = va_arg(ap, int);
	if (meta.precision == -1 && (flag_p = flag_p + 1))
		meta.precision = va_arg(ap, int);
	if (meta.width < 0 && flag_w)
	{
		meta.width = -meta.width;
		meta.flag = '-';
	}
	if (meta.precision < 0 && flag_p)
		meta.precision = 0;
	return (meta);
}
