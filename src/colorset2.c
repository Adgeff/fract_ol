/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 05:23:50 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 06:56:07 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int					ft_color5(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter < itermax / 2)
			colortab[i] = (-(~colortab[i] & 0xFF)) * 1000 / (itermax / 2)
				* iter / 1000 + (~colortab[i] & 0xFF);
		else if (iter == itermax / 2)
			colortab[i] = 0x0;
		else if (iter < itermax)
			colortab[i] = colortab[i] * 1000 / (itermax / 2)
				* iter / 1000 - colortab[i];
		else
			colortab[i] = 0x0;
		i++;
	}
	return (color);
}

int					ft_color6(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter < itermax / 2)
			colortab[i] = (255 - (~colortab[i] & 0xFF)) * 1000 / (itermax / 2)
				* iter / 1000 + (~colortab[i] & 0xFF);
		else if (iter == itermax / 2)
			colortab[i] = 0xFF;
		else if (iter < itermax)
			colortab[i] = (colortab[i] - 255) * 1000 / (itermax / 2) *
				iter / 1000 + (colortab[i] - ((colortab[i] - 255) * 1000) /
				(itermax / 2) * itermax / 1000);
		else
			colortab[i] = 0xFF;
		i++;
	}
	return (color);
}

int					ft_color7(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter < itermax / 2)
			colortab[i] = (-(~colortab[i] & 0xFF)) * 1000 / (itermax / 2)
				* iter / 1000 + (~colortab[i] & 0xFF);
		else if (iter == itermax / 2)
			colortab[i] = 0x0;
		else if (iter < itermax)
			colortab[i] = colortab[i] * 1000 / (itermax / 2)
				* iter / 1000 - colortab[i];
		else
			colortab[i] = 0xFF;
		i++;
	}
	return (color);
}

int					ft_color8(int iter, int itermax, int color)
{
	unsigned char	*colortab;
	int				i;

	colortab = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		if (iter < itermax / 2)
			colortab[i] = (255 - (~colortab[i] & 0xFF)) * 1000 / (itermax / 2)
				* iter / 1000 + (~colortab[i] & 0xFF);
		else if (iter == itermax / 2)
			colortab[i] = 0xFF;
		else if (iter < itermax)
			colortab[i] = (colortab[i] - 255) * 1000 / (itermax / 2) *
				iter / 1000 + (colortab[i] - ((colortab[i] - 255) * 1000) /
				(itermax / 2) * itermax / 1000);
		else
			colortab[i] = 0x0;
		i++;
	}
	return (color);
}
