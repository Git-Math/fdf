/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:24:59 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/12 04:01:11 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (size <= 0)
		return (NULL);
	s = (char *)malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	ft_bzero((void *)s, size);
	return ((void *)s);
}
