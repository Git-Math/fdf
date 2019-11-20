/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 00:07:19 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/15 18:23:22 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_nb(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		n++;
	}
	return (n);
}

static size_t	word_len(char const *s, size_t i, char c)
{
	size_t n;

	n = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s1;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(s1 = (char **)malloc(sizeof(char *) * (word_nb(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		if (!(s1[j++] = ft_strsub(s, (unsigned int)i, word_len(s, i, c))))
			return (NULL);
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
	}
	if (!(s1[j] = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	s1[j] = 0;
	return (s1);
}
