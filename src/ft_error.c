/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:47:01 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 12:51:31 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char		*ft_getexecname(char *path)
{
	char	*chr;

	if (!(chr = ft_strchr(path, '/')))
		return (path);
	return (chr + 1);
}

void		ft_errarg(char *name, char *arg)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": invalid argument\n", 2);
}

void		ft_usage(char *name)
{
	int		i;

	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" [ ", 2);
	i = 0;
	while (ft_fracttab()[i].f)
	{
		ft_putstr_fd(ft_fracttab()[i].name, 2);
		ft_putchar_fd(' ', 2);
		i++;
	}
	ft_putstr_fd("]\n", 2);
}
