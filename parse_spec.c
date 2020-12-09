/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:34:38 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/30 15:52:32 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_flag(char **str, t_specs *specs)
{
	if (**str == '-')
		specs->fg_minus = 1;
	if (**str == '0')
		specs->fg_zero = 1;
}

static void		parse_conv(char **str, t_specs *specs)
{
	if (ft_strchr("%dixXcspu", **str))
		specs->conversion = **str;
	else
		(*str)--;
}

static void		get_wid_from_arg(char **str, t_specs *specs)
{
	if (**str == '*')
		specs->width = va_arg(specs->args, int);
}

void			parse_spec(char **str, t_specs *specs)
{
	while (ft_strchr("-.*0123456789", **str))
	{
		parse_flag(str, specs);
		get_wid_from_arg(str, specs);
		if (**str >= '0' && **str <= '9')
		{
			specs->width = ft_atoi(str);
			continue;
		}
		else if (**str == '.' && (*str)++)
		{
			specs->precision = 0;
			if (**str == '*')
				specs->precision = va_arg(specs->args, int);
			else if (**str >= '0' && **str <= '9')
			{
				specs->precision = ft_atoi(str);
				continue;
			}
			else
				break ;
		}
		(*str)++;
	}
	parse_conv(str, specs);
}
