/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:42:29 by pkari             #+#    #+#             */
/*   Updated: 2021/09/06 14:42:31 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	buff;
	void	*str;

	buff = (count * size);
	str = malloc(buff);
	if (!str)
		return (NULL);
	ft_bzero(str, buff);
	return ((void *)str);
}
