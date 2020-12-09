/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:52:16 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/29 22:24:07 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(t_specs *specs)
{
	if (specs->width < 0)
	{
		specs->width = specs->width * -1;
		specs->fg_minus = 1;
	}
}
