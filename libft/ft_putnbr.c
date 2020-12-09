/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:55:00 by akezanna          #+#    #+#             */
/*   Updated: 2020/01/28 15:58:17 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(long int nb)
{
	long int	nbr;
	int			count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}
