/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:53:42 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 16:04:20 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char *tmp;

	if (f == NULL || s == NULL)
		return ;
	tmp = s;
	while (*tmp)
	{
		f(tmp);
		tmp++;
	}
}
