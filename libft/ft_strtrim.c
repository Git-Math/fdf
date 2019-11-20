/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:23:35 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/15 17:49:14 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	int		end;
	int		i;
	char	*s1;

	if (!s)
		return (NULL);
	st = 0;
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st])
		st++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && s[st])
		end--;
	s1 = (char *)malloc(sizeof(char) * (end - st + 2));
	if (!s1)
		return (NULL);
	i = 0;
	while (st + i <= end)
	{
		s1[i] = s[st + i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
