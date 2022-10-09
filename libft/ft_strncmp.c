/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:08:10 by dgallard          #+#    #+#             */
/*   Updated: 2020/11/14 18:43:16 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	i = 0;
	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	while (i != n && (pstr1[i] != '\0' || pstr2[i] != '\0'))
	{
		if (pstr1[i] != pstr2[i])
			return (pstr1[i] - pstr2[i]);
		i++;
	}
	return (0);
}
