/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 06:47:17 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 06:57:39 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int					ft_color9(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter == itermax)
			colortab[i] = 0x0;
		else
			colortab[i] = colortab[i] * 1000 / (itermax / 10) *
				(iter % (itermax / 10)) / 1000;
		i++;
	}
	return (color);
}

int					ft_color10(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter == itermax)
			colortab[i] = 0xFF;
		else
			colortab[i] = (colortab[i] - 255) * 1000 / (itermax / 10) *
				(iter % (itermax / 10)) / 1000 + 255;
		i++;
	}
	return (color);
}

int					ft_color11(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter == itermax)
			colortab[i] = 0xFF;
		else
			colortab[i] = colortab[i] * 1000 / (itermax / 10) *
				(iter % (itermax / 10)) / 1000;
		i++;
	}
	return (color);
}

int					ft_color12(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter == itermax)
			colortab[i] = 0x0;
		else
			colortab[i] = (colortab[i] - 255) * 1000 / (itermax / 10) *
				(iter % (itermax / 10)) / 1000 + 255;
		i++;
	}
	return (color);
}
