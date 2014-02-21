/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 13:55:15 by cheron            #+#    #+#             */
/*   Updated: 2013/12/22 18:05:32 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fdf.h>
#include <libft.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_get_coord(int x, int y, int z, t_coord *coord)
{
	x *= 50;
	z *= -4;
	coord->x = (x - y * 50) * 0.894427191 + 0.45 * TAB_WIDTH;
	coord->y = (z + (x + y * 50) * 0.4472135955) + 0.1 * TAB_HEIGHT;
}


int		ft_expose_hook(t_env *e)
{
	ft_move_down(e, e->dlst, 0, 0);
	return (0);
}

int		ft_key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

void	ft_read_file(char *file, t_dlst **dlst)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(0);
	}
	ft_create_dlst(fd, dlst);
	if (close(fd) == -1)
	{
		perror(file);
		exit(0);
	}
	if (dlst == NULL)
		exit (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_dlst	*dlst;

	dlst = NULL;
	if (ac == 2)
	{
		ft_read_file(av[1], &dlst);
		e.dlst = dlst;
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, TAB_WIDTH, TAB_HEIGHT, av[1]);
		mlx_key_hook(e.win, ft_key_hook, &e);
		mlx_expose_hook(e.win, ft_expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putendl("usage is : ./fdf <file>");
	return (0);
}
