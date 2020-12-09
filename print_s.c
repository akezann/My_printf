/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:06:35 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/30 14:18:11 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parseprint_str(t_specs *specs,
		t_parseprint *parseprint, int len_str)
{
	check_width(specs);
	if (specs->width && specs->precision < 0)
		parseprint->width_print = specs->width - len_str;
	else if (specs->width && specs->precision >= 0)
	{
		if (specs->precision > len_str)
			parseprint->width_print = specs->width - len_str;
		else if (specs->precision >= 0 && specs->precision <= len_str)
			parseprint->width_print = specs->width - specs->precision;
	}
	parseprint->prec_print = specs->precision;
}

static	int		print_s_with_fgminus(t_specs *specs,
		t_parseprint *parseprint, char *str)
{
	int len;

	len = 0;
	if (specs->fg_minus && !specs->fg_zero)
	{
		if (parseprint->prec_print >= 0)
			len += printstr_len(str, check_pos(parseprint->prec_print));
		else if (parseprint->prec_print < 0)
			len += ft_putstr_fd(str, 1);
		len += printchar_time(' ', check_pos(parseprint->width_print));
	}
	return (len);
}

static	int		print_s_with_fgzero(t_specs *specs,
		t_parseprint *parseprint, char *str)
{
	int len;

	len = 0;
	if (specs->fg_zero && !specs->fg_minus)
	{
		len += printchar_time('0', check_pos(parseprint->width_print));
		if (parseprint->prec_print >= 0)
			len += printstr_len(str, check_pos(parseprint->prec_print));
		else if (parseprint->prec_print < 0)
			len += ft_putstr_fd(str, 1);
	}
	return (len);
}

static	int		print_s_with_nofg(t_specs *specs,
		t_parseprint *parseprint, char *str)
{
	int len;

	len = 0;
	if (!specs->fg_zero && !specs->fg_minus)
	{
		len += printchar_time(' ', check_pos(parseprint->width_print));
		if (parseprint->prec_print >= 0)
			len += printstr_len(str, check_pos(parseprint->prec_print));
		else if (parseprint->prec_print < 0)
			len += ft_putstr_fd(str, 1);
	}
	return (len);
}

int				print_s(t_specs *specs, t_parseprint *parseprint)
{
	int		len_str;
	int		len;
	char	*str;

	len = 0;
	len_str = 0;
	str = va_arg(specs->args, char *);
	len_str = ft_strlen(str);
	init_parseprint(parseprint);
	parseprint_str(specs, parseprint, len_str);
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	if (str == NULL)
	{
		str = "(null)";
		if (specs->precision >= 0 && specs->precision <= 6)
			parseprint->width_print = specs->width - specs->precision;
		else
			parseprint->width_print = specs->width - ft_strlen(str);
		parseprint->prec_print = specs->precision;
	}
	len += print_s_with_fgminus(specs, parseprint, str);
	len += print_s_with_fgzero(specs, parseprint, str);
	len += print_s_with_nofg(specs, parseprint, str);
	return (len);
}
