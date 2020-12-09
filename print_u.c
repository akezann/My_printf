/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:06:19 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/30 15:52:04 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_print(t_specs *specs,
		t_parseprint *parseprint, int len_int)
{
	check_width(specs);
	if ((specs->width && specs->precision < 0))
	{
		parseprint->width_print = specs->width - len_int;
		return ;
	}
	else if (specs->width && specs->precision >= 0)
	{
		if (specs->precision > 0 && specs->precision < len_int)
		{
			parseprint->width_print = specs->width - len_int;
			return ;
		}
		else
		{
			parseprint->width_print = specs->width - specs->precision;
			parseprint->prec_print = specs->precision - len_int;
			return ;
		}
	}
	else if (specs->precision > 0 && !specs->width)
	{
		parseprint->prec_print = specs->precision - len_int;
		return ;
	}
}

static int		print_u_with_fgzero(t_specs *specs,
		t_parseprint *parseprint, unsigned int n)
{
	int len;

	len = 0;
	if (specs->precision >= 0)
	{
		len += printchar_time(' ', check_pos(parseprint->width_print));
		len += printchar_time('0', check_pos(parseprint->prec_print));
		len += ft_putnbr(n);
	}
	else
	{
		len += printchar_time('0', check_pos(parseprint->width_print));
		len += ft_putnbr(n);
	}
	return (len);
}

static int		print_u_with_fgminus(t_parseprint *parseprint, unsigned int n)
{
	int len;

	len = 0;
	if (parseprint->prec_print >= 0)
		len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putnbr(n);
	len += printchar_time(' ', check_pos(parseprint->width_print));
	return (len);
}

static int		print_u_with_nofg(t_parseprint *parseprint, unsigned int n)
{
	int len;

	len = 0;
	len += printchar_time(' ', check_pos(parseprint->width_print));
	len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putnbr(n);
	return (len);
}

int				print_u(t_specs *specs, t_parseprint *parseprint)
{
	unsigned int	n;
	int				len_int;
	int				len;

	len = 0;
	n = (unsigned)va_arg(specs->args, int);
	len_int = len_digit(n);
	init_parseprint(parseprint);
	parse_print(specs, parseprint, len_int);
	if ((specs->fg_minus && specs->fg_zero) ||
			((specs->fg_minus && specs->precision > 0)))
		specs->fg_zero = 0;
	if (n == 0 && specs->precision == 0)
	{
		len += printchar_time(' ', check_pos(specs->width));
		return (len);
	}
	if (specs->fg_minus && !specs->fg_zero)
		len += print_u_with_fgminus(parseprint, n);
	else if (specs->fg_zero && !specs->fg_minus)
		len += print_u_with_fgzero(specs, parseprint, n);
	else if (!specs->fg_minus && !specs->fg_zero)
		len += print_u_with_nofg(parseprint, n);
	return (len);
}
