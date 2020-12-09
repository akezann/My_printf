/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:59:06 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/29 21:18:21 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parseprint_int(t_specs *specs,
		t_parseprint *parseprint, long int n, int len_int)
{
	check_width(specs);
	if (specs->width && specs->precision < 0)
		parseprint->width_print = specs->width - len_int;
	else if (specs->width >= 0 && specs->precision >= 0)
		if (specs->precision > 0 && specs->precision < len_int)
		{
			parseprint->width_print = specs->width - len_int;
		}
		else
		{
			if (n < 0)
			{
				parseprint->width_print = specs->width - specs->precision - 1;
				parseprint->prec_print = specs->precision - len_int + 1;
			}
			else
			{
				parseprint->width_print = specs->width - specs->precision;
				parseprint->prec_print = specs->precision - len_int;
			}
		}
	else if (specs->precision && !specs->width)
		parseprint->prec_print = specs->precision - len_int;
}

static int		print_int_with_fgzero(t_specs *specs,
		t_parseprint *parseprint, long int n)
{
	int len;

	len = 0;
	if (specs->precision < 0)
	{
		if (n < 0)
		{
			len += ft_putchar('-');
			n = n * -1;
		}
		len += printchar_time('0', check_pos(parseprint->width_print));
		len += ft_putnbr(n);
	}
	else if (specs->precision > 0)
	{
		len += printchar_time(' ', check_pos(parseprint->width_print));
		if (n < 0)
		{
			len += ft_putchar('-');
			n = n * -1;
		}
		len += printchar_time('0', check_pos(parseprint->prec_print));
		len += ft_putnbr(n);
	}
	return (len);
}

static int		print_int_with_fgminus(t_parseprint *parseprint, long int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = n * -1;
	}
	if (parseprint->prec_print >= 0)
		len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putnbr(n);
	len += printchar_time(' ', check_pos(parseprint->width_print));
	return (len);
}

static int		print_int_with_nofg(t_parseprint *parseprint, long int n)
{
	int len;

	len = 0;
	len += printchar_time(' ', check_pos(parseprint->width_print));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = n * -1;
	}
	len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putnbr(n);
	return (len);
}

int				print_int(t_specs *specs, t_parseprint *parseprint)
{
	long int	n;
	int			len_int;
	int			len;

	n = va_arg(specs->args, int);
	len_int = len_digit(n);
	len = 0;
	init_parseprint(parseprint);
	parseprint_int(specs, parseprint, n, len_int);
	if (n == 0 && specs->precision == 0)
	{
		len += printchar_time(' ', check_pos(specs->width));
		return (len);
	}
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	if (specs->fg_minus && !specs->fg_zero)
		len += print_int_with_fgminus(parseprint, n);
	else if (specs->fg_zero && !specs->fg_minus)
		len += print_int_with_fgzero(specs, parseprint, n);
	else if (!specs->fg_minus && !specs->fg_zero)
		len += print_int_with_nofg(parseprint, n);
	return (len);
}
