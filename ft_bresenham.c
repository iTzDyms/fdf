/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:33:50 by npineau           #+#    #+#             */
/*   Updated: 2013/12/22 17:55:46 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fdf.h"

void	ft_draw_line(t_env *env, t_coord start, t_coord end, int color)
{
	t_coord	d;
	t_coord	s;
	t_coord	err;

	d.x = (start.x - end.x >= 0 ? start.x - end.x : end.x - start.x);
	d.y = (start.y - end.y >= 0 ? start.y - end.y : end.y - start.y);
	s.x = (start.x < end.x ? 1 : -1);
	s.y = (start.y < end.y ? 1 : -1);
	err.x = (d.x > d.y ? d.x : -d.y) / 2;
	mlx_pixel_put(env->mlx, env->win, start.x, start.y, color);
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(env->mlx, env->win, start.x, start.y, color);
		err.y = err.x;
		if (err.y > -d.x)
		{
			err.x -= d.y;
			start.x += s.x;
		}
		if (err.y < d.y)
		{
			err.x += d.x;
			start.y += s.y;
		}
	}
}
