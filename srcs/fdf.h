/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:49:42 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 16:51:50 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TAB_WIDTH 2000
# define TAB_HEIGHT 2000
# define COLOR 16777215

typedef struct		s_dlst
{
	int				height;
	int				jump;
	struct s_dlst	*right;
	struct s_dlst	*down;
}				t_dlst;

typedef struct	s_coord
{
	int				y;
	int				x;
}				t_coord;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_dlst			*dlst;
}				t_env;

void	ft_create_dlst(int fd, t_dlst **dlst);
t_dlst	*ft_dlstnew(int content, t_dlst *left, t_dlst *up);
void	ft_draw_line(t_env *e, t_coord current, t_coord dir, int color);
void	ft_draw(t_env *e, t_dlst *dlst, int x, int y);
void	ft_move_down(t_env *e, t_dlst *dlst, int x, int y);
void	ft_get_coord(int x, int y, int z, t_coord *coord);

#endif
