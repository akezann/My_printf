/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:11:06 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 18:24:33 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_l_x(unsigned int n, int base)
{
	static char *rep;
	static char conv[50];
	char		*ptr;

	rep = "0123456789abcdef";
	if (n == 0)
		return ("0");
	ptr = &conv[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = rep[n % base];
		n = n / base;
	}
	return (ptr);
}
