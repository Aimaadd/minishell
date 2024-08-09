/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 08:52:20 by abentaye          #+#    #+#             */
/*   Updated: 2024/08/08 16:09:15 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*s2_ptr;

	while (*s1)
	{
		s2_ptr = s2;
		while (*s2_ptr)
		{
			if (*s1 == *s2_ptr)
				return ((char *)s1);
			s2_ptr++;
		}
		s1++;
	}
	return (0);
}
