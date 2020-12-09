/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:06:07 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/30 08:57:45 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_perc(t_specs *specs)
{
	int len;

	len = 0;
	check_width(specs);
	if (specs->fg_minus && specs->fg_zero)
		specs->fg_zero = 0;
	if (!specs->fg_minus && !specs->fg_zero)
	{
		len += printchar_time(' ', check_pos(specs->width - 1));
		len += ft_putchar('%');
	}
	else if (specs->fg_minus && !specs->fg_zero)
	{
		len += ft_putchar('%');
		len += printchar_time(' ', check_pos(specs->width - 1));
	}
	else if (specs->fg_zero && !specs->fg_minus)
	{
		len += printchar_time('0', check_pos(specs->width - 1));
		len += ft_putchar('%');
	}
	return (len);
}
