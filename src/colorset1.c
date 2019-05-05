/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:33:30 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 06:48:33 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			ft_color1(int iter, int itermax, int color)
{
	int		tab[12];

	tab[0] = 0x60FFFFFF;
	tab[1] = 0x40FFFFFF;
	tab[2] = 0x20FFFFFF;
	tab[3] = color | 0x30000000;
	tab[4] = color | 0x70000000;
	tab[5] = color | 0xB0000000;
	tab[6] = 0xD0FFFFFF;
	tab[7] = 0xB0FFFFFF;
	tab[8] = 0x90FFFFFF;
	tab[9] = (0xFFFFFF - color) | 0x30000000;
	tab[10] = (0xFFFFFF - color) | 0x70000000;
	tab[11] = (0xFFFFFF - color) | 0xB0000000;
	if (iter == itermax)
		return (0x0);
	return (tab[iter % 12]);
}

int			ft_color2(int iter, int itermax, int color)
{
	int		tab[12];

	tab[0] = 0xD0FFFFFF;
	tab[1] = 0xB0FFFFFF;
	tab[2] = 0x90FFFFFF;
	tab[3] = color | 0x30000000;
	tab[4] = color | 0x70000000;
	tab[5] = color | 0xB0000000;
	tab[6] = 0x60FFFFFF;
	tab[7] = 0x40FFFFFF;
	tab[8] = 0x20FFFFFF;
	tab[9] = (0xFFFFFF - color) | 0x30000000;
	tab[10] = (0xFFFFFF - color) | 0x70000000;
	tab[11] = (0xFFFFFF - color) | 0xB0000000;
	if (iter == itermax)
		return (0xFFFFFF);
	return (tab[iter % 12]);
}

int			ft_color3(int iter, int itermax, int color)
{
	int		tab[6];

	tab[0] = 0x90FFFFFF;
	tab[1] = 0xB0FFFFFF;
	tab[2] = 0xD0FFFFFF;
	tab[3] = color | 0xB0000000;
	tab[4] = color | 0x70000000;
	tab[5] = color | 0x30000000;
	if (iter == itermax)
		return (0xFFFFFFF);
	return (tab[iter % 6]);
}

int			ft_color4(int iter, int itermax, int color)
{
	int		tab[6];

	tab[0] = 0x20FFFFFF;
	tab[1] = 0x40FFFFFF;
	tab[2] = 0x60FFFFFF;
	tab[3] = color | 0x30000000;
	tab[4] = color | 0x70000000;
	tab[5] = color | 0xB0000000;
	if (iter == itermax)
		return (0x0);
	return (tab[iter % 6]);
}
