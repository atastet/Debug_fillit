/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lst_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:38:40 by atastet           #+#    #+#             */
/*   Updated: 2018/05/18 15:53:08 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"
#include <stdio.h>

/*static t_tetrimino	*new_lst(void)
{
	t_tetrimino *lst;

	if ((lst = (t_tetrimino*)malloc(sizeof(t_tetrimino))) == NULL)
		return (NULL);
	lst->next = NULL;
	return (lst);
}*/

static int			fill_tetriminos(char **tab, int k, int l, t_tetrimino *lst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (l < 21)
	{
		if (tab[k][l] == '\n' || tab[k][l] == '\0')
		{
			lst->tetrimino[i][j] = '\0';
			j = 0;
			i++;
			l++;
			if ((lst->tetrimino[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
				return (0);
		}
		l++;
		lst->tetrimino[i][j] = tab[k][l];
		dprintf(2, "%d, %d, %d\n\n", lst->tetrimino[i][j], i, j);
		j++;
	}
	return (i);
}

/*static int			end_of_tet(t_tetrimino **lst, int a, char **tab, int k)
{
	a++;
	fill_x(*lst);
	fill_y(*lst);
	if (k < ft_tablen(tab) - 1)
	{
		(*lst)->next = new_lst();
		(*lst) = (*lst)->next;
	}
	return (a);
}*/

t_tetrimino			*make_lst_tetriminos(char **tab_tet)
{
	t_tetrimino	*lst_start;
	t_tetrimino	*lst;
	int			a;
	int			i;
	int			k;

	(void)tab_tet;
	i = 0;
	k = -1;
	a = 65;
	if ((lst = (t_tetrimino*)malloc(sizeof(t_tetrimino))) == NULL)
		return (NULL);
	lst->next = NULL;
	lst_start = lst;
	while (tab_tet[++k] && k < 1)
	{
		if ((lst->tetrimino = (char**)malloc(sizeof(char*) * 5)) == NULL)
			return (NULL);
		lst->letter = a;
		if (((lst->tetrimino[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
				|| (!(i = fill_tetriminos(tab_tet, k, 0, lst))))
			return (NULL);
		lst->tetrimino[i] = NULL;
		i = 0;
	//	a = end_of_tet(&lst, a, tab_tet, k);
	}
	lst->next = NULL;
	return (lst_start);
}
