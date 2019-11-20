/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 21:54:19 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/12 05:46:30 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	len_s1;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = strlen(s1);
	len = strlen(s1) + strlen(s2);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len_s1)
	{
		s[i] = (char)s1[i];
		i++;
	}
	while (i < len)
	{
		s[i] = (char)s2[i - len_s1];
		i++;
	}
	s[i] = 0;
	return (s);
}
