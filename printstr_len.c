/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:37:54 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/30 14:07:19 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printstr_len(char *str, int len)
{
	int count;

	count = 0;
	if (len < 0)
		return (0);
	while (*str && len > 0)
	{
		count += ft_putchar(*str);
		str++;
		len--;
	}
	return (count);
}
