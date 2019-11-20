/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:09:33 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/10 17:13:38 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = 0;
	while (*s)
	{
		if (*s == c)
			tmp = s;
		s++;
	}
	if (*s == c)
		tmp = s;
	return ((char *)tmp);
}
