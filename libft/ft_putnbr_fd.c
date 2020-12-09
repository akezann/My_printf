/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:58:11 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/26 16:37:27 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(long int n, int fd)
{
	long int num;

	if (n == 0)
		ft_putchar_fd(0 + '0', fd);
	if (n != 0 && n / 10 != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n > 0)
			ft_putchar_fd(n % 10 + '0', fd);
		else
		{
			num = n * -1;
			ft_putchar_fd(num % 10 + '0', fd);
		}
	}
	else if (n != 0 && (n / 10 == 0) && (n % 10 != 0) && (n > 0))
		ft_putchar_fd(n % 10 + '0', fd);
	else if (n != 0 && (n / 10 == 0) && (n % 10 != 0) && (n < 0))
	{
		num = n * -1;
		ft_putchar_fd('-', fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	return (1);
}
