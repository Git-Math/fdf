/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:51:33 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 16:23:28 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	while (n > 0)
	{
		*tmp_dst = *tmp_src;
		dst++;
		if (*tmp_src == (char)c)
			return (dst);
		tmp_dst++;
		tmp_src++;
		n--;
	}
	return (NULL);
}
