/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:02:59 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 16:52:27 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_right(t_env *e, t_dlst *dlst, int x, int y)
{
	if (dlst)
	{
		ft_draw(e, dlst, x, y);
		return (ft_move_right(e, dlst->right, x + 1, y));
	}
}

void	ft_move_down(t_env *e, t_dlst *dlst, int x, int y)
{
	if (dlst)
	{
		if (dlst->jump == 1)
			return (ft_move_down(e, dlst->down, x, y + 1));
		ft_move_right(e, dlst, x, y);
		return (ft_move_down(e, dlst->down, x, y + 1));
	}
}

void	ft_draw(t_env *e, t_dlst *dlst, int x, int y)
{
	t_coord	current;
	t_coord	dir;
	int		color;

	ft_get_coord(x, y, dlst->height, &current);
	if (dlst->down)
	{
		if (dlst->down->jump != 1)
			ft_get_coord(x, y + 1, dlst->down->height, &dir);
		color = ((dlst->down->height + 1) * (dlst->height + 1)) * 61500;
		color = COLOR - ((color - 61500) % 16777215);
		ft_draw_line(e, current, dir, color);
	}
	if (dlst->right)
	{
		color = ((dlst->right->height + 1) * (dlst->height + 1)) * 61500;
		color = COLOR - ((color - 61500) % 16777215);
		ft_get_coord(x + 1, y, dlst->right->height, &dir);
		ft_draw_line(e, current, dir, color);
	}
}
