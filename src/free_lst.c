#include "../libft/libft.h"
#include "../include/fillit.h"
#include <stdio.h>
void	free_lst(t_tetrimino *lst)
{
	t_tetrimino		*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		ft_tabdel(&lst->tetrimino);
		lst = lst->next;
		free(tmp);
	}
}
