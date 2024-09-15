/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:46 by abentaye          #+#    #+#             */
/*   Updated: 2023/04/26 20:32:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (len == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < len - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
