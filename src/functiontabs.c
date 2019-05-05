/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functiontabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:35:25 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 11:58:42 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_fract					*ft_fracttab(void)
{
	static t_fract		fracttab[] = {
		{"mandelbrot", &ft_mandelbrot, 1},
		{"julia", &ft_julia, 0},
		{"burningship", &ft_burningship, 1},
		{"tricorn", &ft_tricorn, 1},
		{"circle", &ft_circle, 1},
		{"julia84", &ft_julia84, 0},
		{"hourglass", &ft_hourglass, 0},
		{"checkerboard", &ft_checkerboard, 0},
		{NULL, NULL, 0}};

	return (fracttab);
}

t_color					*ft_colortab(void)
{
	static t_color colortab[] = {
		{&ft_color1},
		{&ft_color2},
		{&ft_color3},
		{&ft_color4},
		{&ft_color5},
		{&ft_color6},
		{&ft_color7},
		{&ft_color8},
		{&ft_color9},
		{&ft_color10},
		{&ft_color11},
		{&ft_color12},
		{NULL}};

	return (colortab);
}

t_keyevent				*ft_keyeventtab(void)
{
	static t_keyevent	keyeventtab[] = {
		{NKPL_KEY, &ft_zoomup},
		{NKMN_KEY, &ft_zoomdown},
		{PL_KEY, &ft_iterup},
		{MN_KEY, &ft_iterdown},
		{UP_KEY, &ft_shiftup},
		{DOWN_KEY, &ft_shiftdown},
		{RIGHT_KEY, &ft_shiftright},
		{LEFT_KEY, &ft_shiftleft},
		{NK6_KEY, &ft_colorup},
		{NK3_KEY, &ft_colordown},
		{NK5_KEY, &ft_powerup},
		{NK2_KEY, &ft_powerdown},
		{NK4_KEY, &ft_fractup},
		{NK1_KEY, &ft_fractdown},
		{SP_KEY, &ft_lock},
		{H_KEY, &ft_help},
		{R_KEY, &ft_reset},
		{ESC_KEY, &ft_exit},
		{0, NULL}};

	return (keyeventtab);
}
