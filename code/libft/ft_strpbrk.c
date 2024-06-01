/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 08:52:20 by abentaye          #+#    #+#             */
/*   Updated: 2024/06/01 08:54:22 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL 0

char *ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        const char *s2_ptr = s2;
        while (*s2_ptr)
        {
            if (*s1 == *s2_ptr)
                return (char*)s1;
            s2_ptr++;
        }
        s1++;
    }
    return (NULL);
}