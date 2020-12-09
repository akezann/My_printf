/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:06:27 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 18:32:53 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_specs *specs)
{
	char	c;
	int		len;

	len = 0;
	c = va_arg(specs->args, int);
	check_width(specs);
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	if (!specs->fg_minus && !specs->fg_zero)
	{
		len += printchar_time(' ', check_pos(specs->width - 1));
		len += ft_putchar(c);
	}
	else if (specs->fg_minus && !specs->fg_zero)
	{
		len += ft_putchar(c);
		len += printchar_time(' ', check_pos(specs->width - 1));
	}
	else if (specs->fg_zero && !specs->fg_minus)
	{
		len += printchar_time('0', check_pos(specs->width - 1));
		len += ft_putchar(c);
	}
	return (len);
}
