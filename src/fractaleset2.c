/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractaleset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:14:33 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/29 21:34:03 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int				ft_julia84(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c = env->c;
	z = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_addz(ft_powerz(z, 8), ft_powerz(z, 4)), c);
		z = (t_complex){z.r, -z.i};
		i++;
	}
	return (i);
}

int				ft_hourglass(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c = env->c;
	z = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = (t_complex){z.r * z.i + c.r, z.r / z.i + c.i};
		i++;
	}
	return (i);
}

int				ft_checkerboard(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c = (t_complex){0.0, 0.0};
	z = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_powerz(z, env->power), c);
		z = (t_complex){2 * cos(z.r), 2 * cos(z.i)};
		i++;
	}
	return (i);
}
