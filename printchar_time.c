/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:18:29 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 18:36:36 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printchar_time(char c, int time)
{
	int count;

	count = 0;
	while (time)
	{
		ft_putchar(c);
		time--;
		count++;
	}
	return (count);
}
