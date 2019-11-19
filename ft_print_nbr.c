/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:43:05 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/19 14:00:57 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		act_custom_write_zero(char *str, int a, int b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str[i] == '-')
	{
		write(1, "-", 1);
		j++;
		i = -1;
	}
	while (i++ < (a - b))
		ft_putchar('0');
	write(1, &str[j], b);
	return ((i - 1 + j) + b);
}

int		act_width_lt_precision_nbr(t_meta_print meta, char *str, int len_str)
{
	if (len_str > meta.precision)
		return (write(1, str, len_str));
	else
		return (act_custom_write_zero(str, meta.precision, len_str));
	return (0);
}

int		act_width_gt_precision_nbr(t_meta_print meta, char *str, int len_str)
{
	int x;
	int i;

	i = 0;
	x = 0;
	if (meta.precision >= len_str)
	{
		if (meta.flag == '-')
			x = act_custom_write_zero(str, meta.precision, len_str);
		if (str[0] == '-')
			meta.width--;
		while (i++ < (meta.width - meta.precision))
			ft_putchar(' ');
		if (meta.flag != '-')
			x = act_custom_write_zero(str, meta.precision, len_str);
		return (x + (i - 1));
	}
	if (meta.width > len_str)
		return (act_custom_write(meta, str, meta.width, len_str));
	else
		return (write(1, str, len_str));
}

int		ft_print_nbr_short(t_meta_print meta, char *str, int len_str)
{
	if (str[0] == '0' && ft_strlen(str) == 1 && meta.precision == 0)
		str[0] = ' ';
	if (meta.precision == -2 && meta.width > 0)
	{
		if (len_str < meta.width)
		{
			if (meta.flag == '0')
			{
				if (str[0] == '-')
					meta.width--;
				return (act_custom_write_zero(str, meta.width, len_str));
			}
			return (act_custom_write(meta, str, meta.width, len_str));
		}
		else
			return (write(1, str, len_str));
	}
	if (meta.width < meta.precision)
		return (act_width_lt_precision_nbr(meta, str, len_str));
	if (meta.width > meta.precision)
		return (act_width_gt_precision_nbr(meta, str, len_str));
	if (meta.width == meta.precision)
		return (act_custom_write_zero(str, meta.precision, len_str));
	return (0);
}

int		ft_print_nbr(t_meta_print meta, va_list ap)
{
	char		*s;
	int			i;

	i = 0;
	meta = check_var_meta(meta, ap);
	if (meta.specifier == 'x' || meta.specifier == 'X' || meta.specifier == 'p')
		s = decimal_to_hex(va_arg(ap, unsigned int), meta.specifier);
	if (meta.specifier == 'u')
		s = ft_uint_itoa(va_arg(ap, unsigned int));
	else if (meta.specifier == 'd' || meta.specifier == 'i')
		s = ft_itoa(va_arg(ap, int));
	s = act_null_check((char *)s);
	if ((meta.width <= 0 && meta.precision <= 0))
	{
		if (meta.specifier != 'p' && ft_strlen(s) > 0)
			if (meta.precision == 0 && s[0] == '0')
				return (0 * ft_free(s));
		return (ft_free(s) * write(1, s, ft_strlen(s)));
	}
	if ((meta.width > 0) || (meta.precision > 0))
		i = ft_print_nbr_short(meta, s, ft_strlen(s));
	return (i * ft_free(s));
}
