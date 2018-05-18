/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:37:42 by atastet           #+#    #+#             */
/*   Updated: 2018/05/18 15:10:59 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include "../libft/libft.h"

static char		**str_to_tab(char *buf, char **tab_tet, int nb_tet)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	while (y < nb_tet)
	{
		if ((tab_tet[y] = (char*)malloc(sizeof(char) * (20 + 1))) == NULL)
			return (NULL);
		while (x < 20)
		{
			tab_tet[y][x] = buf[i];
			i++;
			x++;
		}
		tab_tet[y][20] = '\0';
		x = 0;
		y++;
		i++;
	}
	tab_tet[y] = NULL;
	return (tab_tet);
}

static int		get_nb_tetriminos(char *buf)
{
	int		nb_tet;
	int		i;

	i = 0;
	nb_tet = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			nb_tet++;
		i++;
	}
	return (nb_tet);
}

char			**read_tetriminos(char *argv)
{
	char	buf[BUF_SIZE + 1];
	char	**tab_tet;
	int		ret;
	int		fd;
	int		nb_tet;

	ret = 1;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_putstr("open() failed\n");
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
		buf[ret] = '\0';
	if ((simple_check(buf)) == -1)
		return (NULL);
	nb_tet = get_nb_tetriminos(buf);
	if ((tab_tet = (char**)malloc(sizeof(char*) * (nb_tet + 1))) == NULL)
		return (NULL);
	if ((!(tab_tet = str_to_tab(buf, tab_tet, nb_tet)))
			|| ((second_check(tab_tet, nb_tet)) == -1))
	{
		ft_tabdel(&tab_tet);
		return (NULL);
	}
	return (tab_tet);
}
