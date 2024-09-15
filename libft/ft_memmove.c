/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:48:10 by abentaye          #+#    #+#             */
/*   Updated: 2023/04/25 00:13:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
