/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:13:31 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 19:39:33 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_specs(t_specs *specs)
{
	specs->width = 0;
	specs->precision = -1;
	specs->conversion = 0;
	specs->fg_zero = 0;
	specs->fg_minus = 0;
}

int		ft_printf(char *format, ...)
{
	t_specs			*specs;
	t_parseprint	*parseprint;
	int				len;

	parseprint = malloc(sizeof(t_parseprint));
	specs = malloc(sizeof(t_specs));
	len = 0;
	va_start(specs->args, format);
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format);
		if (*format == '%')
		{
			init_specs(specs);
			format++;
			parse_spec(&format, specs);
			len += print_arg(specs, parseprint);
		}
		format++;
	}
	va_end(specs->args);
	free(specs);
	free(parseprint);
	return (len);
}
