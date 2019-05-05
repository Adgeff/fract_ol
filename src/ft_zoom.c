/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:49:15 by geargenc          #+#    #+#             */
/*   Updated: 2018/03/04 20:25:27 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_zoomup(t_env *env)
{
	env->zoom *= ZOOM_STEP;
	env->x_shift *= ZOOM_STEP;
	env->y_shift *= ZOOM_STEP;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}

void	ft_zoomdown(t_env *env)
{
	env->zoom /= ZOOM_STEP;
	env->x_shift /= ZOOM_STEP;
	env->y_shift /= ZOOM_STEP;
	if (ft_drawpic(env))
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.ptr,
		env->img.x, env->img.y);
}
