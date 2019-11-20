/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:06:51 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 17:18:54 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*t_dst;
	const char	*t_src;

	t_src = src;
	t_dst = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	t_src += len;
	t_dst += len;
	while (len--)
		*--t_dst = *--t_src;
	return (dst);
}
