/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:10:30 by mnguyen           #+#    #+#             */
/*   Updated: 2015/02/06 18:10:55 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coderror(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	else if (c == 'G')
		perror("get_next_line ");
	else if (c == '1')
		perror("libft (strdup) ");
	exit(0);
}
