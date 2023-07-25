/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:05 by osavas            #+#    #+#             */
/*   Updated: 2023/07/25 16:40:06 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	a(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**dizi;
	size_t	i;
	size_t	j;
	size_t	z;

	if (!s)
		return (NULL);
	dizi = (char **)malloc((a((char *)s, c) + 1) * sizeof(char *));
	if (!dizi)
		return (NULL);
	i = 0;
	j = 0;
	z = 0;
	while (i <= ft_strlen(s) && a((char *)s, c) != 0 && z < a((char *)s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		dizi[z++] = ft_substr(s, i, j);
		i += j;
	}
	dizi[z] = 0;
	return (dizi);
}
