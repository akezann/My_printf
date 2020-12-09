/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:55:16 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/07 21:32:16 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned	lens1;
	unsigned	lens2;
	char		*sj;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(sj = malloc(lens1 + lens2 + 1)))
		return (0);
	ft_memcpy(sj, s1, lens1);
	ft_memcpy(sj + lens1, s2, lens2 + 1);
	return (sj);
}
