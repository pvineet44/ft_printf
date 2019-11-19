/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:49:51 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 16:36:22 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_meta_print				init_meta(t_meta_print meta)
{
	meta.flag = 0;
	meta.width = 0;
	meta.precision = -2;
	meta.specifier = -2;
	meta.id = "cspdiuxX";
	meta.zeros = 0;
	meta.spaces = 0;
	return (meta);
}

t_meta_print				ft_set_flags(t_meta_print meta, const char *str)
{
	int i;

	i = 0;
	if (str[1] == '0' || str[1] == '-')
		meta.flag = str[1];
	while (str[++i] && i < 3)
		if (str[i] != '0' && str[i] != '-')
			break ;
	meta.width = ft_atoi((char *)&str[i]);
	if (meta.width == 0 && str[i] == '*' && (i = i + 1))
		meta.width = -1;
	if (meta.width == 0 && !ft_isdigit(str[i]))
		meta.width = -2;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		meta.precision = ft_atoi((char *)&str[++i]);
		if (meta.precision == 0 && str[i] == '*' && (i = i + 1))
			meta.precision = -1;
		while (ft_isdigit(str[i]))
			i++;
	}
	meta.specifier = str[i];
	return (meta);
}

int							act_print(t_meta_print meta, va_list ap)
{
	int x;

	x = 0;
	if (meta.specifier == 'c')
		x = ft_print_char(meta, ap);
	if (meta.specifier == 's')
		x = ft_print_str(meta, ap);
	if (meta.specifier == 'p')
		x = ft_print_nbr(meta, ap);
	if (meta.specifier == 'd')
		x = ft_print_nbr(meta, ap);
	if (meta.specifier == 'i')
		x = ft_print_nbr(meta, ap);
	if (meta.specifier == 'u')
		x = ft_print_nbr(meta, ap);
	if (meta.specifier == 'x')
		x = ft_print_nbr(meta, ap);
	if (meta.specifier == 'X')
		x = ft_print_nbr(meta, ap);
	return (x);
}

t_meta_print				init_set_print(t_meta_print meta, const char *str,\
int i, va_list ap)
{
	meta = init_meta(meta);
	meta = ft_set_flags(meta, &str[i]);
	meta.count += act_print(meta, ap);
	return (meta);
}

int							ft_printf(const char *str, ...)
{
	int				i;
	va_list			ap;
	t_meta_print	meta;

	i = -1;
	va_start(ap, str);
	meta.count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' && (i = i + 1))
			{
				meta.count += write(1, "%", 1);
				continue;
			}
			meta = init_set_print(meta, &str[0], i, ap);
			while ((ft_strchr(meta.id, str[i]) == NULL) && i < ft_strlen(str))
				i++;
		}
		else
			meta.count += write(1, &str[i], 1);
	}
	va_end(ap);
	return (meta.count);
}
