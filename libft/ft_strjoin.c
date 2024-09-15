/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:32:50 by abentaye          #+#    #+#             */
/*   Updated: 2023/04/25 17:00:18 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	lentot;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lentot = len1 + len2;
	s = malloc (sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	*(s + lentot) = '\0';
	return (s);
}
