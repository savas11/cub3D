/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:16 by osavas            #+#    #+#             */
/*   Updated: 2023/07/25 16:41:17 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	unsigned int	i;
	char			*source;
	char			*dizi;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	source = (char *)s;
	dizi = (char *)malloc(len + 1 * sizeof(char));
	if (!dizi)
		return (NULL);
	while (i < len)
	{
		dizi[i] = source[start + i];
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}
