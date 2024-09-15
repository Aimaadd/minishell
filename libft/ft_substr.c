/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:31:24 by abentaye          #+#    #+#             */
/*   Updated: 2023/04/26 20:27:33 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t max)
{
	size_t	c;

	c = 0;
	while (s[c] && max--)
		c++;
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	allocsize;
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i] && i < start)
		i++;
	if (s[i] == '\0')
		allocsize = 1;
	else
		allocsize = ft_strnlen(s + i, len) + 1;
	ptr = (char *)malloc(sizeof(char) * allocsize);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + i, allocsize);
	return (ptr);
}
