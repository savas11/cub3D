/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:39:39 by osavas            #+#    #+#             */
/*   Updated: 2023/07/25 16:39:41 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char *)dst;
	j = (unsigned char *)src;
	if (i < j)
	{
		while (len--)
			*i++ = *j++;
	}
	else
	{
		i += len;
		j += len;
		while (len--)
			*--i = *--j;
	}
	return (dst);
}
