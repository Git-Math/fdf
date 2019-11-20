/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:58:30 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 15:42:14 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i] && s2[j] && (i + j) < n)
			j++;
		i++;
	}
	if (s2[j])
		return (NULL);
	else if (j == 0)
		return ((char *)s1);
	else
		return ((char *)s1 + i - 1);
}
