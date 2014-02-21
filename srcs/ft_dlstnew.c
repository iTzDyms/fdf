/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:02:51 by cheron            #+#    #+#             */
/*   Updated: 2013/12/22 19:24:38 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fdf.h>

t_dlst	*ft_dlstnew(int content, t_dlst *left, t_dlst *up)
{
	t_dlst	*new;

	if (!(new = (t_dlst *) malloc(sizeof(t_dlst))))
		return (NULL);
	new->height = content;
	new->jump = 0;
	if (up)
		up->down = new;
	if (left)
		left->right = new;
	new->right = NULL;
	new->down = NULL;
	return (new);
}
