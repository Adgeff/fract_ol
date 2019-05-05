/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_fract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:25:48 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/06 12:54:13 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_colorup(t_env *env)
{
	if (ft_colortab()[env->color_index + 1].f)
		env->color_index++;
	else
		env->color_index = 0;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void	ft_colordown(t_env *env)
{
	if (env->color_index > 0)
		env->color_index--;
	else
		while (ft_colortab()[env->color_index + 1].f)
			env->color_index++;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void	ft_fractup(t_env *env)
{
	if (ft_fracttab()[env->fract_index + 1].f)
		env->fract_index++;
	else
		env->fract_index = 0;
	env->lock = ft_fracttab()[env->fract_index].lock;
	ft_reset(env);
}

void	ft_fractdown(t_env *env)
{
	if (env->fract_index > 0)
		env->fract_index--;
	else
		while (ft_fracttab()[env->fract_index + 1].f)
			env->fract_index++;
	env->lock = ft_fracttab()[env->fract_index].lock;
	ft_reset(env);
}
