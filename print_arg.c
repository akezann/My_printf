/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:37:00 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 18:37:46 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_arg(t_specs *specs, t_parseprint *parseprint)
{
	int len;

	len = 0;
	if (specs->conversion == 'c')
		len += print_c(specs);
	if (specs->conversion == 'd' || specs->conversion == 'i')
		len += print_int(specs, parseprint);
	if (specs->conversion == 's')
		len += print_s(specs, parseprint);
	if (specs->conversion == 'u')
		len += print_u(specs, parseprint);
	if (specs->conversion == 'x')
		len += print_l_x(specs, parseprint);
	if (specs->conversion == 'X')
		len += print_u_x(specs, parseprint);
	if (specs->conversion == 'p')
		len += print_p(specs, parseprint);
	if (specs->conversion == '%')
		len += print_perc(specs);
	return (len);
}
