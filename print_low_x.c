/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:07:09 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 17:42:01 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_print_int(t_specs *specs, t_parseprint *parseprint,
		int len_int)
{
	check_width(specs);
	if ((specs->width && specs->precision < 0))
		parseprint->width_print = specs->width - len_int;
	else if (specs->width && specs->precision >= 0)
	{
		if (specs->precision < len_int)
		{
			parseprint->width_print = specs->width - len_int;
		}
		else
		{
			parseprint->width_print = specs->width - specs->precision;
			parseprint->prec_print = specs->precision - len_int;
		}
	}
	else if (specs->precision > 0 && !specs->width)
		parseprint->prec_print = specs->precision - len_int;
}

static int		print_x_with_fgzero(t_specs *specs,
		t_parseprint *parseprint, char *hex)
{
	int len;

	len = 0;
	if (specs->fg_zero && !specs->fg_minus)
	{
		if (specs->precision < 0)
		{
			len += printchar_time('0', check_pos(parseprint->width_print));
			len += ft_putstr_fd(hex, 1);
		}
		else
		{
			len += printchar_time(' ', check_pos(parseprint->width_print));
			len += printchar_time('0', check_pos(parseprint->prec_print));
			len += ft_putstr_fd(hex, 1);
		}
	}
	return (len);
}

static int		print_x_with_fgminus(t_specs *specs,
		t_parseprint *parseprint, char *hex)
{
	int len;

	len = 0;
	if (specs->fg_minus && !specs->fg_zero)
	{
		if (parseprint->prec_print >= 0)
			len += printchar_time('0', check_pos(parseprint->prec_print));
		len += ft_putstr_fd(hex, 1);
		len += printchar_time(' ', check_pos(parseprint->width_print));
	}
	return (len);
}

static int		print_x_with_nofg(t_specs *specs, t_parseprint *parseprint,
		char *hex)
{
	int len;

	len = 0;
	if (!specs->fg_minus && !specs->fg_zero)
	{
		len += printchar_time(' ', check_pos(parseprint->width_print));
		len += printchar_time('0', check_pos(parseprint->prec_print));
		len += ft_putstr_fd(hex, 1);
	}
	return (len);
}

int				print_l_x(t_specs *specs, t_parseprint *parseprint)
{
	char				*hex;
	unsigned long int	n;
	int					len;
	int					len_hex;

	len = 0;
	len_hex = 0;
	n = va_arg(specs->args, int);
	hex = conv_l_x(n, 16);
	len_hex = ft_strlen(hex);
	init_parseprint(parseprint);
	parse_print_int(specs, parseprint, len_hex);
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	if (*hex == '0' && specs->precision == 0)
	{
		len += printchar_time(' ', check_pos(specs->width));
		return (len);
	}
	len += print_x_with_fgminus(specs, parseprint, hex);
	len += print_x_with_fgzero(specs, parseprint, hex);
	len += print_x_with_nofg(specs, parseprint, hex);
	return (len);
}
