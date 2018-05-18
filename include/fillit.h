/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:39:05 by atastet           #+#    #+#             */
/*   Updated: 2018/05/15 18:49:21 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	int					width;
	int					height;
	struct s_tetrimino	*next;
}						t_tetrimino;

void					ft_usage(void);
char					**read_tetriminos(char *argv);
int						simple_check(char *buf);
int						second_check(char **tab_tet, int nb_tet);
t_tetrimino				*make_lst_tetriminos(char **tab_tet);
char					**make_grid(t_tetrimino *lst, int size_grid);
t_tetrimino				*arrange_tet(t_tetrimino *lst);
int						get_width(char **tet);
int						get_height(char **tet);
void					fill_y(t_tetrimino *lst);
void					fill_x(t_tetrimino *lst);
void					free_lst(t_tetrimino *lst);
void					free_grid(char **grid);

#endif
