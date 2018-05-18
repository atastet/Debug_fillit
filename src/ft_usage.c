/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:38:07 by atastet           #+#    #+#             */
/*   Updated: 2018/05/08 10:38:09 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [File containing between 2 and 26 Tetriminos]");
	ft_putendl("        Note : If file contains more than 26 Tetriminos,");
	ft_putendl("               The program will run slowly.");
}
