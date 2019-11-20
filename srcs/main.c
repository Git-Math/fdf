/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:14:14 by mnguyen           #+#    #+#             */
/*   Updated: 2015/02/09 19:07:24 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeall(t_coor ***map)
{
	int		i;

	i = 0;
	while (*map[i])
	{
		free(*map[i]);
		++i;
	}
	free(*map);
}

int		ft_maxln(t_coor *map)
{
	int i;
	int et;

	i = 0;
	et = 0;
	while (et == 0)
	{
		if (map[i].etat == 'F')
			et = 1;
		i++;
	}
	return (i);
}

void	ft_fdf(t_mlx point)
{
	int		i;
	int		j;
	int		et;
	int		max;

	i = 0;
	while (point.map[i])
	{
		if (point.map[i + 1])
			max = ft_maxln(point.map[i + 1]);
		j = 0;
		et = 0;
		while (et != 1)
		{
			if (point.map[i][j].etat == 'F')
				et = 1;
			else
				drt(point.mlx, point.new, point.map[i][j], point.map[i][j + 1]);
			if (point.map[i + 1] && j < max)
				drt(point.mlx, point.new, point.map[i][j], point.map[i + 1][j]);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx point;

	if (ac == 2)
	{
		point.map = stockmap(av[1], &point.dim);
		newcoor(point.map, point.dim, redim(point.dim));
		point.mlx = mlx_init();
		point.new = mlx_new_window(point.mlx, WIDTH, HEIGHT, "Test FDF");
		mlx_expose_hook(point.new, expose_hook, &point);
		mlx_key_hook(point.new, key_hook, &point);
		mlx_loop(point.mlx);
		freeall(&point.map);
	}
	else
		ft_putendl("**** Nombre d'arguments incorrect (1) ****");
	return (0);
}
