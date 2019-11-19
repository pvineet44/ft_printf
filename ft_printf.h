/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:25:55 by vparekh           #+#    #+#             */
/*   Updated: 2019/11/18 16:27:59 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_meta_print
{
	char	flag;
	int		width;
	int		precision;
	char	specifier;
	int		count;
	char	*id;
	char	*zeros;
	char	*spaces;
}				t_meta_print;

void			ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_atoi(char *str);
int				ft_strlen(const char *str);
t_meta_print	parse_printf_args(t_meta_print meta, char *args);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_printf(const char *str, ...);
int				ft_putnbr(int nb);
int				ft_nbrlen(int n);
int				ft_print_str(t_meta_print meta, va_list ap);
int				ft_print_nbr(t_meta_print meta, va_list ap);
char			*act_null_check(char *str);
t_meta_print	check_var_meta(t_meta_print meta, va_list ap);
char			*ft_itoa(int nbr);
char			*ft_strdup(const char *s1);
int				act_custom_write(t_meta_print meta, char *str, int a, int b);
int				ft_print_char(t_meta_print meta, va_list ap);
char			*ft_uint_itoa(unsigned int nbr);
char			*decimal_to_hex(unsigned int decimal, char c);
int				ft_free(char *str);

#endif
