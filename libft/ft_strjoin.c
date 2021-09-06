/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:49:26 by pkari             #+#    #+#             */
/*   Updated: 2021/09/06 14:49:28 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy1(char const *s1, char *strnew)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	return (strnew);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strnew;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		strnew = (char *)malloc(sizeof(char) * (i + j + 1));
		if (!strnew)
			return (NULL);
		j = 0;
		strnew = ft_copy1(s1, strnew);
		while (s2[j] != '\0')
		{
			strnew[i + j] = s2[j];
			j++;
		}
		strnew[i + j] = '\0';
		return (strnew);
	}
	return (NULL);
}
