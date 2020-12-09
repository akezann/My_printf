/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:05:49 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 17:49:29 by akezanna         ###   ########.fr       */
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
		if (specs->precision < len_int)
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

static int		print_p_with_fgzero(t_specs *specs,
		t_parseprint *parseprint, char *ptr)
{
	int len;

	len = 0;
	if (specs->precision < 0)
	{
		len += write(1, "0x", 2);
		len += printchar_time('0', check_pos(parseprint->width_print - 2));
		len += ft_putstr_fd(ptr, 1);
	}
	else
	{
		len += printchar_time(' ', check_pos(parseprint->width_print - 2));
		len += write(1, "0x", 2);
		len += printchar_time('0', check_pos(parseprint->prec_print));
		len += ft_putstr_fd(ptr, 1);
	}
	return (len);
}

static int		print_p_with_fgminus(t_parseprint *parseprint, char *ptr)
{
	int len;

	len = 0;
	len += write(1, "0x", 2);
	if (parseprint->prec_print >= 0)
		len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putstr_fd(ptr, 1);
	len += printchar_time(' ', check_pos(parseprint->width_print - 2));
	return (len);
}

static int		print_p_with_nofg(t_parseprint *parseprint, char *ptr)
{
	int len;

	len = 0;
	len += printchar_time(' ', check_pos(parseprint->width_print - 2));
	len += write(1, "0x", 2);
	len += printchar_time('0', check_pos(parseprint->prec_print));
	len += ft_putstr_fd(ptr, 1);
	return (len);
}

int				print_p(t_specs *specs, t_parseprint *parseprint)
{
	char	*ptr;
	int		len;
	int		len_ptr;

	ptr = conv_ptr((unsigned long)va_arg(specs->args, void *), 16);
	len = 0;
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	(*ptr == '0' && specs->precision == 0) ? ptr = "" : (0);
	len_ptr = ft_strlen(ptr);
	init_parseprint(parseprint);
	parse_print(specs, parseprint, len_ptr);
	if (*ptr == '0' && specs->precision == 0)
	{
		len += write(1, "0x", 2);
		len += printchar_time(' ', check_pos(specs->width - 2));
		return (len);
	}
	if (specs->fg_minus && !specs->fg_zero)
		len += print_p_with_fgminus(parseprint, ptr);
	else if (specs->fg_zero && !specs->fg_minus)
		len += print_p_with_fgzero(specs, parseprint, ptr);
	else if (!specs->fg_minus && !specs->fg_zero)
		len += print_p_with_nofg(parseprint, ptr);
	return (len);
}
