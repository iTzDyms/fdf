/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:47:13 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 16:52:49 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

static void		ft_parse_line(char *line, t_dlst **left, t_dlst *up);
static int		ft_get_nbr(char *line, int *i);


void			ft_create_dlst(int fd, t_dlst **dlst)
{
	char	*line;
	int		ret;
	t_dlst	*up;

	up = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_parse_line(line, dlst, up);
		up = *dlst;
		dlst = &(*dlst)->down;
		free(line);
	}
}

static void		ft_parse_line(char *line, t_dlst **dlst, t_dlst *up)
{
	int		i;
	t_dlst	*new;

	i = 0;
	new = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '+' || line[i] == '-' || ft_isdigit(line[i]))
		{
			new = ft_dlstnew(ft_get_nbr(line, &i), *dlst, up);
			if (*dlst)
				dlst = &new;
			else
				*dlst = new;
			if (up)
				up = up->right;
		}
		i++;
	}
	if (new == NULL)
	{
		new = ft_dlstnew(0, *dlst, up);
		new->jump = 1;
		*dlst = new;
	}
}

static int		ft_get_nbr(char *line, int *i)
{
	int		sign;
	int		ret;

	sign = 1;
	ret = 0;
	while (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sign = -sign;
		*i += 1;
	}
	while (ft_isdigit(line[*i]))
	{
		ret = (ret * 10) + (line[*i] - '0');
		*i += 1;
	}
	while (ft_isdigit(line[*i] || line[*i] == '+' || line[*i] == '-'))
		*i += 1;
	return (sign * ret);
}

