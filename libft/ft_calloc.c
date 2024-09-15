/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:23:37 by abentaye          #+#    #+#             */
/*   Updated: 2023/05/03 21:26:01 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		allocsize;

	if (count && (size > (SIZE_MAX / count)))
		return (NULL);
	allocsize = count * size;
	ptr = malloc(allocsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, allocsize);
	return (ptr);
}
