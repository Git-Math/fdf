/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:11:42 by mnguyen           #+#    #+#             */
/*   Updated: 2015/02/16 15:26:39 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**tabreal(char **tab, char *newline, int len)
{
	int		i;
	char	**realtab;

	i = 0;
	if (!newline)
		return (tab);
	if (!(realtab = (char **)malloc(sizeof(char *) * (len + 2))))
		coderror('M');
	while (len != 0 && i < len)
	{
		(realtab[i] = ft_strdup(tab[i])) ? i : coderror('1');
		ft_strclr(tab[i]);
		free(tab[i]);
		i++;
	}
	(realtab[i] = ft_strdup(newline)) ? i : coderror('1');
	realtab[i + 1] = NULL;
	return (realtab);
}

char	**getnext(char *param, int *len)
{
	int		fd;
	int		ret;
	char	*str;
	char	**tab;

	if ((fd = open(param, O_RDONLY)) == -1)
		coderror('O');
	while ((ret = get_next_line(fd, &str)) != 0)
	{
		if (ret == -1)
			coderror('G');
		tab = tabreal(tab, str, (*len)++);
		if (str)
			ft_strclr(str);
	}
	if ((close(fd)) == -1)
		coderror('C');
	return (tab);
}

t_coor	**stockmap(char *param, t_ix *dim)
{
	int		i;
	int		len;
	char	**tab;
	t_coor	**map;

	len = 0;
	tab = getnext(param, &len);
	if (!(map = (t_coor **)malloc(sizeof(t_coor *) * (len + 1))))
		coderror('M');
	i = 0;
	dim->xmin = 2147483647;
	dim->xmax = -2147483648;
	dim->ymin = 2147483647;
	dim->ymax = -2147483648;
	dim->zmin = 2147483647;
	dim->zmax = -2147483648;
	while (i < len)
	{
		if (ft_strlen(tab[i]))
			map[i] = getnbr(tab[i], i, dim);
		i++;
	}
	map[i] = NULL;
	map = putcolor(map, dim);
	return (map);
}
