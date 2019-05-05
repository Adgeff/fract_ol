/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 08:30:06 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/03 13:00:33 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	ft_addz(t_complex a, t_complex b)
{
	return ((t_complex){a.r + b.r, a.i + b.i});
}

t_complex	ft_subz(t_complex a, t_complex b)
{
	return ((t_complex){a.r - b.r, a.i - b.i});
}

t_complex	ft_mulz(t_complex a, t_complex b)
{
	return ((t_complex){a.r * b.r - a.i * b.i, a.r * b.i + b.r * a.i});
}

t_complex	ft_divz(t_complex a, t_complex b)
{
	double			c;

	c = b.r * b.r + b.i * b.i;
	return ((t_complex){a.r * b.r / c + a.i * b.i / c,
		a.i * b.r / c - a.r * b.i / c});
}

t_complex	ft_powerz(t_complex n, unsigned int power)
{
	t_complex		result;

	if (power == 0)
		return ((t_complex){1, 0});
	result = n;
	while (power > 1)
	{
		result = ft_mulz(result, n);
		power--;
	}
	return (result);
}
