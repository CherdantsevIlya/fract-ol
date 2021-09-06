/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:48:57 by pkari             #+#    #+#             */
/*   Updated: 2021/09/06 14:48:59 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *source)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (source)
		while (source[i])
			dest[j++] = source[i++];
	dest[j] = '\0';
	return (dest);
}
