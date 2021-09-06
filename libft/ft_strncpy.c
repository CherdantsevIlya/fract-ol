/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:50:53 by pkari             #+#    #+#             */
/*   Updated: 2021/09/06 14:50:55 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *source, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (source && len)
		while (len-- && source[i])
			dest[j++] = source[i++];
	dest[i] = '\0';
	return (dest);
}
