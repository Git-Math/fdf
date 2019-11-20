/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:53:36 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 15:13:20 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i] && s2[j])
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
