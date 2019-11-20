/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:16:26 by mnguyen           #+#    #+#             */
/*   Updated: 2015/02/06 17:55:11 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	isline(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			if (s[i++] == '\n')
				return (1);
	}
	return (0);
}

static int	del(char *s, int r)
{
	if (s)
	{
		ft_strdel(&s);
	}
	return (r);
}

static int	read_line(int const fd, char *s, char **tmp, int r)
{
	char	*buf;
	int		len;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (r == BUFF_SIZE && !isline(*tmp))
	{
		len = 0;
		ft_strclr(buf);
		if ((r = read(fd, buf, BUFF_SIZE)) < 0)
			return (del(buf, -1));
		if (*tmp)
		{
			len = ft_strlen(*tmp);
			if (!(s = ft_strdup(*tmp)))
				return (del(buf, -1));
			ft_strdel(&*tmp);
		}
		if (!(*tmp = (char *)malloc(sizeof(char) * (len + 1 + r))))
			return (del(buf, -1));
		if (s)
			ft_strcpy(*tmp, s);
		ft_strcpy(*tmp + len, buf);
	}
	return (del(buf, r));
}

static char	*save_line(char **s, char *tmp)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	while (tmp[len] != '\n' && tmp[len])
		len++;
	i = 0;
	while (tmp[len + i])
		i++;
	line = NULL;
	free(line);
	*s = NULL;
	free(*s);
	if (i > 1)
		if (!(*s = ft_strsub(tmp, len + 1, i - 1)))
			return (NULL);
	line = ft_strsub(tmp, 0, len);
	free(tmp);
	return (line);
}

int			get_next_line(int const fd, char **line)
{
	static char *s;
	char		*tmp;
	int			r;

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	tmp = NULL;
	if (s)
	{
		tmp = ft_strdup(s);
		free(s);
	}
	r = read_line(fd, s, &tmp, BUFF_SIZE);
	if (r < 0)
		return (-1);
	*line = save_line(&s, tmp);
	if (!*line)
		return (-1);
	if (r == 0 && !*line[0])
		return (0);
	return (1);
}
