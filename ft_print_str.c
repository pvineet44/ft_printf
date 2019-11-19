/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:44:55 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/19 17:25:34 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		act_width_lt_precision(t_meta_print meta, char *str, int len_str)
{
	if (len_str < meta.width)
		return (act_custom_write(meta, str, meta.width, len_str));
	if (len_str <= meta.precision)
		return (write(1, str, len_str));
	if (len_str > meta.precision)
		return (write(1, str, meta.precision));
	return (0);
}

int		act_width_gt_precision(t_meta_print meta, char *str, int len_str)
{
	if (meta.precision > len_str)
		return (act_custom_write(meta, str, meta.width, len_str));
	if (meta.width >= len_str)
		return (act_custom_write(meta, str, meta.width, meta.precision));
	if (len_str > meta.width)
		return (act_custom_write(meta, str, meta.width, meta.precision));
	return (meta.precision);
}

int		ft_print_str_short(t_meta_print meta, char *str, int len_str)
{
	if (meta.precision == -2 && meta.width > 0)
	{
		if (len_str < meta.width)
			return (act_custom_write(meta, str, meta.width, len_str));
		else
			return (write(1, str, len_str));
	}
	if (meta.width < meta.precision)
		return (act_width_lt_precision(meta, str, len_str));
	if (meta.width > meta.precision)
		return (act_width_gt_precision(meta, str, len_str));
	if (meta.width == meta.precision)
	{
		if (meta.width > len_str)
			return (act_custom_write(meta, str, meta.width, len_str));
		else
			return (write(1, str, meta.precision));
	}
	return (0);
}

int		ft_print_str(t_meta_print meta, va_list ap)
{
	char		*s;
	int			i;

	i = 0;
	meta = check_var_meta(meta, ap);
	s = va_arg(ap, char *);
	s = act_null_check((char *)s);
	if (meta.width == 0 && meta.precision == 0)
		return (0);
	if (meta.width == -2 && meta.precision == -2)
		return (write(1, s, ft_strlen(s)));
	if (meta.width == 0 && meta.precision > 0)
	{
		if (ft_strlen(s) > meta.precision)
			return (write(1, s, meta.precision));
		else
			return (write(1, s, ft_strlen(s)));
	}
	while ((meta.precision == 0 && meta.width > 0) && i++ < meta.width)
		ft_putchar(' ');
	if (meta.precision == 0 && meta.width > 0)
		return (i - 1);
	return (ft_print_str_short(meta, s, ft_strlen(s)));
}
