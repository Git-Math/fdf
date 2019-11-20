/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:07:11 by mnguyen           #+#    #+#             */
/*   Updated: 2015/02/10 15:12:35 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colneg(int z, int zmin)
{
	int		dec;

	dec = zmin / 3;
	if (z >= dec)
		return (0x0066FF);
	if (z < dec && z >= dec * 2)
		return (0x0000CC);
	return (0x000066);
}

int		colpos(int z, int zmax)
{
	int		dec;

	dec = zmax / 12;
	if (z <= dec)
		return (0x00CC33);
	if (z > dec && z <= dec * 2)
		return (0x009933);
	if (z > dec * 2 && z <= dec * 3)
		return (0x006633);
	if (z > dec * 3 && z <= dec * 6)
		return (0x996600);
	return (0xFFFFFF);
}
