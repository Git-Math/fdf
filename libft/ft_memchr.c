/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:43:17 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 16:22:23 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		if (*tmp == (char)c)
			return ((void *)s);
		s++;
		tmp++;
		n--;
	}
	return (NULL);
}
