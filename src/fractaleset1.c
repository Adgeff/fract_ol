/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractaleset1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:32:12 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/05 16:54:38 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int				ft_mandelbrot(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z = (t_complex){0, 0};
	c = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_powerz(z, env->power), c);
		i++;
	}
	return (i);
}

int				ft_julia(int x, int y, t_env *env)
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
		z = ft_addz(ft_powerz(z, env->power), c);
		i++;
	}
	return (i);
}

int				ft_burningship(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z = (t_complex){0, 0};
	c = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_powerz(z, env->power), c);
		z = (t_complex){ABS(z.r), ABS(z.i)};
		i++;
	}
	return (i);
}

int				ft_tricorn(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z = (t_complex){0, 0};
	c = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_powerz(z, env->power), c);
		z = (t_complex){z.r, -z.i};
		i++;
	}
	return (i);
}

int				ft_circle(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c = (t_complex){0.9, 0};
	z = (t_complex){((double)x + env->x_shift - FRAC_LEN / 2) / (env->zoom *
		(double)(FRAC_LEN / 4)), ((double)y + env->y_shift - FRAC_LEN / 2) /
		(env->zoom * (double)(FRAC_LEN / 4))};
	i = 0;
	while (i < env->itermax && z.r * z.r + z.i * z.i < 4.0)
	{
		z = ft_addz(ft_subz(ft_addz(ft_powerz(z, 8), ft_powerz(z, 4)), z), c);
		z = (t_complex){ABS(z.r), ABS(z.i)};
		i++;
	}
	return (i);
}
