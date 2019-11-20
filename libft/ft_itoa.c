/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:41:47 by mnguyen           #+#    #+#             */
/*   Updated: 2014/11/13 14:28:16 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*testmin(char *str)
{
	if (ft_strequ(str, "-./,),(-*,("))
		return (ft_strcpy(str, "-2147483648"));
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	int		sign;
	char	*str;

	i = 0;
	sign = 0;
	len = intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (i < len)
	{
		str[len - 1 - i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	str[len] = 0;
	return (testmin(str));
}
