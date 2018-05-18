/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:37:45 by atastet           #+#    #+#             */
/*   Updated: 2018/05/18 15:30:32 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"

int				main(int argc, char **argv)
{
	char		**tab_tet;
	t_tetrimino	*lst;
	//char		**grid;
	int			i;

	i = -1;
	if (argc != 2)
	{
		ft_usage();
		return (-1);
	}
	if ((tab_tet = read_tetriminos(argv[1])) == NULL)
		return (0);
	if (!(lst = make_lst_tetriminos(tab_tet)))
	{
		ft_tabdel(&tab_tet);
		return (0);
	}
	ft_tabdel(&tab_tet);
	lst = arrange_tet(lst);
/*	if (!(grid = make_grid(lst, 3)))
	{
		free_lst(lst);
		ft_tabdel(&grid);
	}*/
	free_lst(lst);
	/*while (grid[++i])
		ft_putendl(grid[i]);
	ft_tabdel(&grid);*/
	while (1);
	return (0);
}
