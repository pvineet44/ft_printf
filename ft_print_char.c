/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:54:20 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/19 17:23:25 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(t_meta_print meta, va_list ap)
{
	char	c;
	int		i;

	i = 0;
	meta = check_var_meta(meta, ap);
	c = (char)va_arg(ap, int);
	if (meta.width == -2)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		if (meta.flag != '-')
			while (i++ < (meta.width - 1))
				ft_putchar(' ');
		ft_putchar(c);
		if (meta.flag == '-')
			while (i++ < (meta.width - 1))
				ft_putchar(' ');
		return (i);
	}
}
