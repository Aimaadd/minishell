/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:06:02 by abentaye          #+#    #+#             */
/*   Updated: 2023/04/26 20:11:01 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_len(int nb)
{
	int	c;

	if (nb == 0)
		return (1);
	c = 0;
	if (nb < 0)
		c++;
	while (nb)
	{
		nb /= 10;
		c++;
	}
	return (c);
}

static void	fill_number(char *buf, unsigned int bufsize, unsigned int nb)
{
	while (bufsize--)
	{
		buf[bufsize] = ((nb % 10) + '0');
		nb /= 10;
	}
}

char	*ft_itoa(int nb)
{
	unsigned int	nblen;
	char			*ptr;

	nblen = nb_len(nb);
	ptr = (char *)malloc(sizeof(char) * (nblen + 1));
	if (!ptr)
		return (NULL);
	ptr[nblen] = '\0';
	if (nb < 0)
	{
		*ptr = '-';
		fill_number(ptr + 1, nblen - 1, (unsigned int)-nb);
	}
	else
	{
		fill_number(ptr, nblen, (unsigned int)nb);
	}
	return (ptr);
}
